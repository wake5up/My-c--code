#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(),a.end());
		reverse(b.begin(), b.end());
		if (a.size() < b.size())
		{
			a.swap(b);
		}
		a.resize(a.size()+1,'0');
		int jw = 0;
		int num = 0;
		int i = 0;
		for (i = 0; i < b.size(); i++)
		{
			num = a[i] + b[i] - 2 * '0' + jw;
			if (num>1)
			{
				jw = num / 2;
				a[i] = num % 2 + '0';
			}
			else
			{
				jw = 0;
				a[i] = num+'0';
			}	
		}
		for (; i < a.size(); i++)
		{
			num = a[i] - '0' + jw;
			if (num>1)
			{
				jw = num / 2;
			}
			else
				jw = 0;
			a[i] = num % 2 + '0';
		}
		reverse(a.begin(),a.end());
		if (a[0] == '0')
			a.erase(a.begin());
		return a;
	}
};

int main()
{
	string s1="0";
	string s2 = "0";
	Solution s;
	string ss=s.addBinary(s1, s2);
	return 0;
}