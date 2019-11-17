#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

#if 0

//变为斐波那契数列的最小步数

void IsFib(int n, int *a, int *b)
{
	int arr[10000];
	arr[0] = 0;
	arr[1] = 1;
	int i = 2;
	while (arr[i-1] < n)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		i++;
	}
	*a = arr[i - 1];
	*b = arr[i - 2];
}

int main()
{
	int n;
	int *a = new int;
	int *b = new int;
	int count = 0;
	while (cin >> n)
	{
		IsFib(n, a, b);
		int n1 = n;
		while (n != *b && n1 != *a)
		{
			--n;
			++n1;
			++count;
		}
		cout << count;
	}
	return 0;
}
#endif



bool IsTrue(string str, int n)
{
	int count = 0;
	for (int i = 0; i<n; i++)
	{
		if (str[i] == '(')
			++count;
		else if (str[i] == ')')
			--count;
		else
			return false;
	}
	if (0 == count)
		return true;
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		string str[30000];
		for (int i = 0; i<n; i++)
		{
			getline(cin, str[i]);
		}
		for (int i = 0; i<n; i++)
		{
			if (IsTrue(str[i], str[i].size()))
			{
				++count; 
			}
		}
		cout << count;
	}
	return 0;
}

