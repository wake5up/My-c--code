#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <vector>

#if 0
bool IsFun1(vector<string> v)
{
	for (int i = 0; i<v.size() - 1; i++)
	{
		if (v[i + 1]<v[i])
			return false;
	}
	return true;
}
bool IsFun2(vector<string> v)
{
	for (int i = 0; i<v.size() - 1; ++i)
	{
		if (v[i + 1].length()<v[i].length())
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		string str;
		vector<string> v;
		for (int i = 0; i<n; ++i)
		{
			cin >> str;
			v.push_back(str);
		}
		if (IsFun1(v) && IsFun2(v))
			cout << "both";
		else if (!IsFun1(v) && !IsFun2(v))
			cout << "none";
		else if (!IsFun1(v) && IsFun2(v))
			cout << "lengths";
		else
			cout << "lexicographically";
	}
	return 0;
}
#endif


int ret(int n, int m)
{
	int temp;
	while (m%n)
	{
		temp=m%n;
		m = n;
		n = temp;
	}
	return n;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n>m)
		{
			int temp = n;
			n = m;
			m = temp;
		}
		int num = n*m / ret(n, m);
		cout << num;
	}
	return 0;
}