//字符全排列
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Fun(string s, int l, int r)
{
	if (l == r)
	{
		cout << s << " ";
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(s[i],s[l]);
			Fun(s,l+1,r);
			swap(s[i],s[l]);
		}
	}
}


int main()
{
	string s;
	while (cin >> s)
	{
		Fun(s,0,s.size()-1);
	}
	return 0;
}