#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;
int main()
{
	while (1)
	{
		int n = 10;
		int arr[10] = { 0 };
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		int i;
		for (i = 0; i<n; i++)
		{
			if (arr[i] != 0)
			{
				cout << arr[i] / 2 << endl;
			}
			else
			{
				break;
			}
		}
		if (arr[i] == 0)
			break;
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size()>b.size())
			swap(a, b);
		string maxstring;
		for (int i = 0; i<a.size(); i++)
		{
			for (int j = i; j<a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if ((int)b.find(temp)<0)
					break;
				else if (maxstring.size()<temp.size())
					maxstring = temp;
			}
		}
		cout << maxstring << endl;
	}
	return 0;
}