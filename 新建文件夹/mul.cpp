//大数相乘

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string Mul(string s1, string s2)
{
	string s;
	vector<int> v(s1.size()+s2.size(),0);
	vector<int> v1(s1.size());
	vector<int> v2(s2.size());
	for (int i = s1.size() - 1, j = 0; i >= 0; j++, i--)
		v1[j] = s1[i] - '0';
	for (int i = s2.size() - 1, j = 0; i >= 0; j++, i--)
		v2[j] = s2[i]-'0';
	int index = v.size() - 1;
	for (int j = 0; j < v2.size(); j++)
	{
		for (int i = 0; i < v1.size(); i++)
		{
			v[i + j] += v1[i] * v2[j];
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]>9)
		{
			v[i] %= 10;
			v[i + 1] = v[i] / 10;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] == 0)
			continue;
		else
			s += to_string(v[i]);
	}
	return s;
}

int main()
{
	string str1 = "11234";
	string str2 = "23";
	string s = Mul(str1,str2);
	return 0;
}