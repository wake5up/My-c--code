#pragma once
#include "HuffmanTree.hpp"
#include <string>
#include <vector>
using namespace std;

//字符的结构体集合
struct CharInfo
{
	//存储一个字符,有符号的char型最大范围是-128~127
	//但是遇到汉字的时候，汉字的编码可能大于127，一旦大于127就是负数了，以后需要用此编码做下标，就会出问题,所以需要使用无符号类型
	unsigned char _ch;
	unsigned long long _count;//long long防止出现字符的次数太多
	string _strCode;//该字符的字符串编码
	CharInfo(unsigned long long count = 0)
		:_count(count)
	{}
	//符号重载
	CharInfo operator+(const CharInfo& c)
	{
		return CharInfo(_count + c._count);
	}
	bool operator>(const CharInfo& c)
	{
		return _count > c._count;
	}
	bool operator!=(const CharInfo& c)const
	{
		return _count != c._count;
	}
};

class FileCompress
{
	friend class GZIP;
public:
	FileCompress();//构造函数
	void CompressFile(const string& strFilePath);//文件压缩函数
	void UNCompressFile(const string& strFilePath);//文件解压缩函数
	void Getline(FILE* pf, string& strContent);
private:
	void GetHuffmanCode(HTNode<CharInfo>* pRoot);//Huffman编码
	void WriteHeadInfo(FILE* pf,const string& strFileName);//解压缩需要原来的文件信息[文件后缀、字符行数、字符及其对应的次数、压缩文件]
	
private:
	vector<CharInfo> _CharInfo;//256个字符结构体数组
};