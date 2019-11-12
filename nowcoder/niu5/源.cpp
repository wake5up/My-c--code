#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include<string>

#if 0
bool IsHui(string a)
{
	for (int i = 0; i<a.length() / 2; i++)
	{
		if (a[i] != a[a.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string a, b, temp;
	while (cin >> a >> b)
	{
		int count = 0;
		for (int i = 0; i<=a.length(); i++)
		{
			temp = a;
			temp.insert(i, b);
			if (IsHui(temp))
			{
				++count;
			}
		}
		cout << count;
	}
	return 0;
}
#endif

int main()
{
	int n;
	int arr[100000] = { 0 };
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		int sum = 0;
		int num = arr[0];
		for (int i = 0; i<n; i++)
		{
			if (arr[i]<0 && arr[i]>num)
			{
				num = arr[i];
			}
			sum += arr[i];
			if (sum>num)
			{
				num = sum;
			}
			if (sum<0)
			{
				sum = 0;
			}
		}
		cout << num;
	}
	return 0;
}