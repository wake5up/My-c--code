#pragma once
#include "Common.h"
#include "LZHashTable.h"
#include <string>

class LZ77
{
	friend class GZIP;
public:
	LZ77();
	~LZ77();
	void CompressFile(const std::string& strFilePath);
	void UNComressFile(const std::string& strFilePath);

private:
	USH longestMatch(USH matchHead, USH& curMatchDist,USH start);
	void WriteFlag(FILE* fOut,UCH& chFlag,UCH& bitCount,bool isCharOrLen);
	void MergeFile(FILE* fOut,ULL fileSize);
	void FileWindow(FILE* fIn,size_t& _lookAhead,USH& start);
	void Getline(FILE* pf, std::string& strContent);
private:
	UCH* _pWin;
	LZHashTable _ht;
};