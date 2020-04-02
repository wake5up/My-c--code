//深拷贝
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

class String
{
public:
	String(char* str = "")
	{
		if (str == nullptr)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str,str);
	}
	String(String&& str)
		:_str(str._str)
	{
		str._str = nullptr;
	}
	String(const String& str)
		:_str(new char[strlen(str._str)+1])
	{
		strcpy(_str,str._str);
	}
	String& operator=(String&& str)
	{
		if (this != &str)
		{
			swap(_str,str._str);
		}
		return *this;
	}
	String& operator=(String& str)
	{
		if (this != &str)
		{
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp,str._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}
	String operator+(const String& str)
	{
		char* temp = new char[strlen(str._str)+strlen(_str)+1];
		strcpy(temp,_str);
		strcpy(temp+strlen(_str),str._str);
		String strRet(temp);
		delete[] temp;
		return strRet;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void Test()
{
	String s1("hello");
	String s2(s1);
	String s3;
	s3 = s1;
	String s4;
	s4= s1 + s2;
}

int main()
{
	Test();
	return 0;
}