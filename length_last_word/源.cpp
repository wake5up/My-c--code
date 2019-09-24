#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}
	return 0;
}