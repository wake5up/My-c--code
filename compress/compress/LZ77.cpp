#define _CRT_SECURE_NO_WARNINGS 1
#include "LZ77.h"
#include "FileCompress.h"
#include <iostream>
#include <assert.h>
using namespace std;

const USH MIN_LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1;//右窗中剩余的字节数
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;//先行缓冲区（待压缩字节）中的开头

LZ77::LZ77()
	:_pWin(new UCH[WSIZE*2])
	, _ht(WSIZE)
{}
LZ77::~LZ77()
{
	delete[] _pWin;
	_pWin = nullptr;
}

void LZ77::CompressFile(const std::string& strFilePath)
{
	FILE* fIn = fopen(strFilePath.c_str(),"rb");
	if (nullptr == fIn)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	//获取文件大小
	fseek(fIn,0,SEEK_END);
	ULL fileSize = ftell(fIn);
	
	//如果文件太小，不压缩
	if (fileSize <= MIN_MATCH)
	{
		cout << "文件太小，不压缩" << endl;
		return;
	}

	//确定压缩文件名
	std::string strfilename(strFilePath.c_str());
	size_t finish = strfilename.rfind('.');
	std::string strUNname(strfilename.substr(0, finish));
	strUNname += ".lzp";

	//从压缩文件中读取一个缓存区的数据到窗口中
	fseek(fIn,0,SEEK_SET);
	size_t lookAhead = fread(_pWin,1,2*WSIZE,fIn);//表示先行缓冲区中剩余子节的个数

	USH hashAddr = 0;
	//处理前两个字符，把前两个字节放入哈希表
	for (USH i = 0; i < MIN_MATCH - 1; ++i)
		_ht.HashFunc(hashAddr,_pWin[i]);

	//压缩
	FILE* fOUT = fopen(strUNname.c_str(), "wb");
	assert(fOUT);

	std::string postFix = strfilename.substr(strfilename.rfind('.'));
	postFix += "\n";
	fwrite(postFix.c_str(),1,postFix.size(),fOUT);

	USH start = 0;
	USH matchHead = 0;
	USH curMatchLength = 0;
	USH curMatchDist = 0;

	//与标记有关的变量
	UCH chFlag = 0; 
	UCH bitCount = 0;
	bool IsLen = false;
	FILE* fOutF = fopen("3.txt","wb");
	assert(fOutF);

	while (lookAhead)
	{
		//将当前三个字符插入到哈希表中，并获取匹配链的头
		_ht.Insert(matchHead,_pWin[start+2],start,hashAddr);

		curMatchLength = 0;
		curMatchDist = 0;

		//验证在查找缓冲区中是否找到匹配--最长匹配
		if (matchHead)
		{ 
			//顺着匹配链找最长匹配，最终带出<长度，距离>对
			curMatchLength = longestMatch(matchHead,curMatchDist,start);
		}
		//验证是否找到匹配
		if (curMatchLength < MIN_MATCH)
		{
			//为找匹配，将start位置的字符写入到压缩文件中
			fputc(_pWin[start],fOUT);
			WriteFlag(fOutF, chFlag, bitCount, false);
			++start;
			lookAhead--;
		}
		else
		{
			//找到匹配，将<长度，距离>对写入到压缩文件中
			UCH chLen = curMatchLength-3;
			fputc(chLen, fOUT);//写长度
			fwrite(&curMatchDist,sizeof(curMatchDist),1,fOUT);//写距离

			WriteFlag(fOutF, chFlag, bitCount, true);//写标记

			//更新先行缓冲区中剩余字节数
			lookAhead -= curMatchLength;

			//将已经匹配的字符串按照三个一组将其插入到哈希表中
			--curMatchLength;
			while (curMatchLength)
			{
				start++; 
				_ht.Insert(matchHead,_pWin[start+2],start,hashAddr);
				curMatchLength--;
			}
			++start;//循环中start少加了一次
		}
		//检测先行缓冲区中剩余字符的个数
		if (lookAhead <= MIN_LOOKAHEAD)
			FileWindow(fIn,lookAhead,start);
	}
	if (bitCount > 0 && bitCount < 8)
	{
		chFlag <<= (8-bitCount);
		fputc(chFlag,fOutF);
	}
	fclose(fOutF);

	MergeFile(fOUT,fileSize);

	fclose(fIn); 
	fclose(fOUT);
	//将用来保存标记信息的临时文件删除掉
}

void LZ77::FileWindow(FILE* fIn, size_t& lookAhead, USH& start)
{
	//压缩已经进行到右窗，先行缓冲区剩余数据不够MIN_LOOKAHEAD
	if (start >= WSIZE)
	{
		//将右窗中的数据搬移到左窗
		memcpy(_pWin, _pWin + WSIZE, WSIZE);
		memset(_pWin + WSIZE, 0, WSIZE);
		start -= WSIZE;
		//更新哈希表
		_ht.Update();
		//向右窗中补充一个WSIZE个的待压缩数据
		if (!feof(fIn))
			lookAhead += fread(_pWin + WSIZE, 1, WSIZE, fIn);
	}
	
}

void LZ77::MergeFile(FILE* fOut, ULL fileSize)
{
	//将压缩数据和标记信息文件合并
	//读取标记文件内容，然后将结果写入到压缩文件中
	FILE* fInF = fopen("3.txt", "rb");
	size_t flagSize = 0;
	UCH* pReadbuff = new UCH[1024];
	while (true)
	{
		size_t rdSize = fread(pReadbuff, 1, 1024, fInF);
		if (0 == rdSize)
			break;
		fwrite(pReadbuff, 1, rdSize, fOut);
		flagSize += rdSize;
	}
	fwrite(&flagSize, sizeof(flagSize), 1, fOut);
	fwrite(&fileSize, sizeof(fileSize), 1, fOut);
	delete[] pReadbuff;
	fclose(fInF);
}

//chFlag：该字节中的每个比特位是用来区分当前字节是原字符还是长度
//bitCount：该字节中的多少个比特位已经被设置
//isCharOrLen：代表该字节是原字符还是长度
//0：原字符
//1：长度
void LZ77::WriteFlag(FILE* fOut, UCH& chFlag, UCH& bitCount, bool isCharOrLen)
{
	chFlag <<= 1;
	if (isCharOrLen)
		chFlag |= 1;
	bitCount++;
	if (bitCount == 8)
	{
		//将该标记写入到压缩文件中
		fputc(chFlag,fOut);
		chFlag = 0;
		bitCount = 0;
	}
}

//匹配：是在查找缓冲区中进行的，查找缓冲区中可能会找到多个匹配
//输出：需要最长匹配
//注意：可能会遇到环状链--解决方法：设置最大的匹配次数
//   匹配是在MAX_DIST范围内进行匹配的，太远的距离则不进行匹配
USH LZ77::longestMatch(USH matchHead, USH& curMatchDist,USH start)
{
	UCH curMatchLen = 0;//一次匹配长度
	UCH maxMatchLen = 0;
	UCH maxMatchCount = 255;//防止环状链
	USH curMatchStart = 0;//当前匹配在查找缓冲区的起始位置

	//查找匹配时，不能太远，不能超过MAX_DIST
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;
	do
	{
		//匹配范围:先行缓冲区
		UCH* pstart = _pWin + start;
		UCH* pend = pstart + MAX_MATCH;
		//查找缓冲区匹配串的起始
		UCH* pMatchStart = _pWin + matchHead;

		curMatchLen = 0;
		while (pstart < pend&&*pstart == *pMatchStart)
		{
			curMatchLen++;
			pstart++;
			pMatchStart++;
		}

		//一次匹配完成
		if (curMatchLen>maxMatchLen)
		{
			maxMatchLen = curMatchLen;
			curMatchStart = matchHead;
		}
	} while((matchHead=_ht.GetNext(matchHead))>limit&&maxMatchCount--);

	curMatchDist = start - curMatchStart;
	return maxMatchLen;
}

//解压缩
void LZ77::UNComressFile(const std::string& strFilePath)
{
	//判断文件后缀是否正确
	std::string postFix = strFilePath.substr(strFilePath.rfind('.'));
	if (".lzp" != postFix)
	{
		cout << "压缩文件格式不对" << endl;
		return;
	}

	//打开压缩文件和标记文件
	FILE* fInD = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fInD)
	{
		cout << "打开文件失败" << endl;
		return;
	}
	//操作标记数据的文件指针
	FILE* fInF = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fInF)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	//获取源文件大小
	ULL fileSize = 0;
	fseek(fInF,0-sizeof(fileSize),SEEK_END);
	fread(&fileSize,sizeof(fileSize),1,fInF);
	//获取标记大小
	size_t flagSize = 0;
	fseek(fInF, 0 - sizeof(fileSize)-sizeof(flagSize), SEEK_END);
	fread(&flagSize,sizeof(flagSize),1,fInF);
	//将读取标记信息的文件指针移动到保存标记数据的起始位置
	fseek(fInF,0-sizeof(flagSize)-sizeof(fileSize)-flagSize,SEEK_END);

	FILE* fInFo = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fInFo)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	fseek(fInFo, 0, SEEK_SET);
	postFix = "";
	Getline(fInFo, postFix);

	size_t finish = strFilePath.rfind('.');//从后往前，找到点的下标
	std::string strUNFileName(strFilePath.substr(0, finish));//获取后缀之前文件名
	strUNFileName += "(副本)";
	strUNFileName += postFix;//文件名加上源文件后缀名

	FILE* fOut = fopen(strUNFileName.c_str(), "wb");
	assert(fOut);

	//用来还原匹配串,读取前文匹配中的内容
	FILE* fR = fopen(strUNFileName.c_str(), "rb");

	UCH bitCount = 0;
	UCH chFlag = 0;
	ULL encodeCount = 0;
	int len = postFix.size() + 1;
	while (len--)
	{
		UCH ch = fgetc(fInD);
	}
	while (encodeCount < fileSize)
	{
		if (0 == bitCount)
		{
			chFlag=fgetc(fInF);
			bitCount = 8;
		}
		if (chFlag & 0x80) 
		{
			//长度距离对
			USH matchLen = fgetc(fInD)+3;
			USH matchDist = 0;
			fread(&matchDist,sizeof(matchDist),1,fInD);

			fflush(fOut);//清空缓冲区

			encodeCount += matchLen;//更新已经解码字节数的大小

			UCH ch;
			fseek(fR,0-matchDist,SEEK_END);
			while (matchLen)
			{
				ch = fgetc(fR);
				fputc(ch,fOut);
				matchLen--;
				fflush(fOut);
			}
		}
		else
		{
			//原字符
			UCH ch = fgetc(fInD);
			fputc(ch,fOut);
			encodeCount += 1;
		}
		chFlag <<= 1;
		bitCount--;
	}
	fclose(fInD);
	fclose(fInF);
	fclose(fOut);
	fclose(fR);
	fclose(fInFo);
}

void LZ77::Getline(FILE* pf, std::string& strContent)
{
	while (!feof(pf))//没有到达文件结尾
	{
		char ch = fgetc(pf);//逐个字符的读取
		if ('\n' == ch)//读到换行符，说明一行读完了
			break;

		strContent += ch;//该字符串不断添加字符
	}
}