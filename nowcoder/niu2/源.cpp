#define _CRT_SECURE_NO_WARNINGS 1

//ÅÅÐò×ÓÐòÁÐ
#if 0
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int *arr = new int[n];
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i<n; i++)
		{
			if (arr[i]>arr[i - 1])
			{
				while (i<n&&arr[i] >= arr[i - 1])
				{
					++i;
				}
				++count;
			}
			else if (arr[i]<arr[i - 1])
			{
				while (i<n&&arr[i]<=arr[i - 1])
				{
					++i;
				}
				++count;
			}
			else
			{
				++i;
			}
		}
		cout << count;
	}
	return 0;
}
#endif

//µ¹ÖÃµ¥´Ê
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int main()
{
	string str;
	while (getline(cin, str))
	{
		int len = str.length();
		reverse(str.begin(), str.end());
		int j = 0;
		for (int i = 0; i<len; i++)
		{
			if (str[i] == ' ')
			{
				reverse(str.begin() + j, str.begin() + i);
				j = i + 1;
			}
		}
		reverse(str.begin() + j, str.end());
		cout << str;
	}
	return 0;
}
