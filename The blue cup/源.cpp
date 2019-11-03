#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<cstdio>
#include<string>
#if 0
//×ÖÄ¸Í¼ÐÎ
int main()
{
	int n, m;
	cin >> n >> m;
	char str[26][26] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i>j)
				str[i][j] = 'A' + (i-j);
			else
				str[i][j] = 'A' + (j-i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << str[i][j];
		}
		cout << endl;
	}
	return 0;
}
#endif

#if 0
int main()
{
	int m,n;
	int arr[32][5];
	for (int i = 0; i < 32; i++)
	{
		n = i;
		for (int j = 4; j >= 0; j--)
		{	
			m = n % 2;
			n /= 2;
			arr[i][j] = m;			
		}
	}
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}
#endif

string fun(int n)
{
	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
	{
		return "yes";
	}
	return "no";
}
int main()
{
	int n;
	cin >> n;
	string ret = fun(n);
	cout << ret;
	return 0;
}