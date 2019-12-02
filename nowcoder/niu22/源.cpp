#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

int IsTrue(int n1, int n2)
{
	int k=1;
	while (k != 0)
	{
		k = n1%n2;
		n1 = n2;
		n2 = k;
	}
	return n1;
}

int main()
{
	int n, m;
	int arr[100000];
	while (cin >> n >> m)
	{
		int sum = m;
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i<n; i++)
		{
			if (arr[i] <= sum)
				sum += arr[i];
			else
				sum += IsTrue(arr[i], sum);
		}
		cout << sum << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		int len = str.size();
		int i = 0;
		for (i = 0; i<len; i++)
		{
			if (str.find(str[i]) == str.rfind(str[i]))
			{
				cout << str[i] << endl;
				break;
			}

		}
		if (i == len)
			cout << -1 << endl;
	}
	return 0;
}