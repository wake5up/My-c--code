#define _CRT_SECURE_NO_WARNINGS
#include "FileCompress.h"
#include "HuffmanTree.hpp"
#include <iostream>
#include <string>
#include <assert.h>

FileCompress::FileCompress()
{
	_CharInfo.resize(256);
	for (size_t i = 0; i < 256; ++i)
	{
		_CharInfo[i]._ch = i;
		_CharInfo[i]._count = 0;
	}
}

//文件压缩函数
void FileCompress::CompressFile(const string& strFilePath)
{
	FILE* Fin = fopen(strFilePath.c_str(),"rb");
	if (nullptr == Fin)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	unsigned char* pReadBuff = new unsigned char[1024];
	
	while (1)
	{
		size_t rdSize = fread(pReadBuff,1,1024,Fin);
		if (0 == rdSize)
			break;
		for (size_t i = 0; i < rdSize; ++i)
		{
			_CharInfo[pReadBuff[i]]._count++;
		}
	}

	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_CharInfo,CharInfo(0));
	GetHuffmanCode(ht.GetpRoot());
	char ch = 0;
	char bitcount = 0;

	std::string strfilename(strFilePath.c_str());
	size_t finish = strfilename.rfind('.');
	std::string strUNname(strfilename.substr(0,finish));
	strUNname += ".hzp";
	FILE* Fout = fopen(strUNname.c_str(),"wb");
	assert(Fout);

	WriteHeadInfo(Fout,strFilePath);
	fseek(Fin,0,SEEK_SET);
	while (1)
	{
		size_t rdsize = fread(pReadBuff,1,1024,Fin);
		if (0 == rdsize)
			break;
		for (size_t i = 0; i < rdsize; ++i)
		{
			string & strCode = _CharInfo[pReadBuff[i]]._strCode;
			for (size_t j = 0; j < strCode.size(); ++j)
			{
				ch <<= 1;
				if ('1' == strCode[j])
					ch |= 1;
				bitcount++;
				if (8 == bitcount)
				{
					fputc(ch,Fout);
					ch = 0;
					bitcount = 0;
				}
			}
		}
	}
	if (bitcount > 0 && bitcount < 8)
	{
		ch <<= (8-bitcount);
		fputc(ch,Fout);
	}
	delete[] pReadBuff;
	fclose(Fin);
	fclose(Fout);
}
//解压缩
void FileCompress::UNCompressFile(const std::string& strFilePath)
{
	//判断文件后缀是否正确
	std::string postFix = strFilePath.substr(strFilePath.rfind('.'));
	if (".hzp" != postFix)
	{
		cout << "压缩文件格式不对" << endl;
		return;
	}

	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "压缩文件打开失败" << endl;
		return;
	}

	//提取压缩文件头部信息第一行【后缀名】
	postFix = "";
	Getline(fIn, postFix);

	//通过压缩文件第二行有效编码行数得到有效字符个数权值
	std::string strContent;
	Getline(fIn, strContent);
	size_t LineCount = 0;
	LineCount = atoi(strContent.c_str());//把字符转换为十进制数

	unsigned long long charCount = 0;
	for (size_t i = 0; i < LineCount; ++i)
	{
		strContent = "";//首先清空字符串
		Getline(fIn, strContent);//获取有效编码行数下的第一行
		if ("" == strContent)//处理换行符，因为刚刚读取到换行符的时候，Getline函数直接返回，没有写入文件
		{
			strContent += "\n";
			Getline(fIn, strContent);//注意：易错点，记得要处理换行符
		}

		charCount = atoi(strContent.c_str() + 2);//[A,1]
		_CharInfo[(unsigned char)strContent[0]]._count = charCount;//易错点，需要类型强转，否则数组下标越界
	}

	//重建huffman树
	HuffmanTree<CharInfo> ht;//类的实例化
	ht.CreateHuffmanTree(_CharInfo, CharInfo(0));

	//解压缩
	size_t finish = strFilePath.rfind('.');//从后往前，找到点的下标
	std::string strUNFileName(strFilePath.substr(0, finish));//获取后缀之前文件名
	strUNFileName += "(副本)";
	strUNFileName += postFix;//文件名加上源文件后缀名
	FILE* fOut = fopen(strUNFileName.c_str(), "wb");//打开解压缩后放内容的文件
	if (nullptr == fOut)
	{
		cout << "打开文件失败" << endl;
		return;
	}
	char* rdBuff = new char[1024];//存储缓冲区
	int pos = 7;
	HTNode<CharInfo>* pCur = ht.GetpRoot();
	unsigned long long fileSize = pCur->_weight._count;

	while (1)
	{
		size_t rdSize = fread(rdBuff, 1, 1024, fIn);//从压缩文件中读取内容至缓冲区
		if (0 == rdSize)
			break;

		for (size_t i = 0; i < rdSize; ++i)//循环rdSize个字节
		{
			pos = 7;
			for (size_t j = 0; j < 8; ++j)//一个字节8位[10010110 11011111 11111100 00000]
			{
				if (rdBuff[i] & (1 << pos))
					pCur = pCur->_pRight;//如果该位是1就往右子树移动
				else
					pCur = pCur->_pLeft;//否则就往左子树移动

				if (nullptr == pCur->_pLeft && nullptr == pCur->_pRight)//当遇到叶子节点时
				{
					fputc(pCur->_weight._ch, fOut);//就可以把叶子节点的字符插入到解压缩文件中去
					pCur = ht.GetpRoot();//让pCur回到根节点
					--fileSize;//解压一个字符根节点总数就少一个
					if (0 == fileSize)//当根节点字符权值总数减少到0时，压缩就完毕了
						break;
				}

				pos--;
				if (pos < 0)//当第一个字节结束时，就需要跳出8位循环，开始下一个字节的循环
					break;
			}
		}
	}

	delete[] rdBuff;
	fclose(fIn);
	fclose(fOut);
}

//获取huffman编码
void FileCompress::GetHuffmanCode(HTNode<CharInfo>* pRoot)
{
	if (nullptr == pRoot)
		return;

	GetHuffmanCode(pRoot->_pLeft);//递归遍历左节点
	GetHuffmanCode(pRoot->_pRight);//递归遍历右节点

	if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)//左节点和右节点同时为空，就是叶子节点
	{
		HTNode<CharInfo>* pCur = pRoot;//叶子节点定为pCur
		HTNode<CharInfo>* pParent = pCur->_pParent;//该叶子节点称为pParent

		std::string& strCode = _CharInfo[pCur->_weight._ch]._strCode;
		while (pParent)//一直倒着从叶子节点到根节点进行编码,直到跟节点为空
		{
			if (pCur == pParent->_pLeft)//如果pCur节点是双亲节点的左子树，置0
				strCode += '0';
			else//如果pCur节点是双亲节点的右子树，置1
				strCode += '1';

			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());//我们是从叶子节点到根节点倒序排列字符串编码的，现在需要逆序恢复从根节点到叶子节点的编码排序
	}
}

//压缩文件的头部信息保留着原来的压缩信息
void FileCompress::WriteHeadInfo(FILE* pf, const std::string& strFileName)
{
	//获取源文件后缀
	std::string postFix = strFileName.substr(strFileName.rfind('.'));
	//有效编码的行数
	size_t LineCount = 0;
	//有效字符及其出现的次数
	std::string strCharCount;
	char buff[1024] = { 0 };
	for (size_t i = 0; i < 256; ++i)//通过这个for循环，就可以从结构体数组中得到有效字符信息
	{
		if (0 != _CharInfo[i]._count)
		{
			strCharCount += _CharInfo[i]._ch;
			strCharCount += ',';
			memset(buff, 0, 1024);
			_itoa(_CharInfo[i]._count, buff, 10);
			strCharCount += buff;
			strCharCount += "\n";
			LineCount++;
		}
	}

	//把三部分内容准备好后，开始整合三部分内容
	std::string strHeadInfo;
	strHeadInfo += postFix;
	strHeadInfo += "\n";

	memset(buff, 0, 1024);
	_itoa(LineCount, buff, 10);
	strHeadInfo += buff;
	strHeadInfo += "\n";

	strHeadInfo += strCharCount;

	//整合信息完毕后，写入到压缩文件中去
	fwrite(strHeadInfo.c_str(), 1, strHeadInfo.size(), pf);
}


//按行获取压缩文件首部信息
void FileCompress::Getline(FILE* pf, std::string& strContent)
{
	while (!feof(pf))//没有到达文件结尾
	{
		char ch = fgetc(pf);//逐个字符的读取
		if ('\n' == ch)//读到换行符，说明一行读完了
			break;

		strContent += ch;//该字符串不断添加字符
	}
}
