#include "FileCompress.h"
#include "LZ77.h"
#include <cstdio>

LZ77 lz;
FileCompress fc;
void FCompress(const std::string& strFilePath)
{
	lz.CompressFile(strFilePath);
	std::string strfilename(strFilePath.c_str());
	size_t finish = strfilename.rfind('.');
	std::string strname(strfilename.substr(0, finish));
	strname += ".lzp";
	fc.CompressFile(strname);

	//删除临时文件
	while (remove(strname.c_str()) == 0);
	while (remove("3.txt") == 0);
}

void FUnCompress(const std::string& strFilePath)
{
	fc.UNCompressFile(strFilePath);
	std::string strfilename(strFilePath.c_str());
	size_t finish = strfilename.rfind('.');
	std::string strUNname(strfilename.substr(0, finish));
	strUNname += ".lzp";
	lz.UNComressFile(strUNname);

	//删除临时文件
	while (remove(strUNname.c_str()) == 0);
}

int main()
{
	//FCompress("黑道特种兵.txt");
	//FUnCompress("黑道特种兵.hzp");
	//FCompress("李荣浩-年少有为1.flac");
	//FUnCompress("李荣浩-年少有为1.hzp");
	FCompress("李荣浩-年少有为.mp4");
	FUnCompress("李荣浩-年少有为.hzp");
	return 0;
}