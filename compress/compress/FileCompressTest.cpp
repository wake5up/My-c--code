#include "FileCompress.h"

int main()
{
	FileCompress fc;
	fc.CompressFile("1.txt");
	fc.UNCompressFile("1.hzp");
	fc.CompressFile("动态规划.docx");
	fc.UNCompressFile("动态规划.hzp");
	fc.CompressFile("李荣浩-年少有为.mp4");
	fc.UNCompressFile("李荣浩-年少有为.hzp");
	fc.CompressFile("李荣浩-年少有为.flac");
	fc.UNCompressFile("李荣浩-年少有为.hzp");
	return 0;
}