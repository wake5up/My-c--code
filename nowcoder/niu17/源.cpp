#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 2)
			cout << "-1" << endl;
		else if (n % 2 == 1)
			cout << "2" << endl;
		else if (n % 4 == 0)
			cout << "3" << endl;
		else
			cout << "4" << endl;
	}
	return 0;
}
#endif

string Add(string str1, string str2)
{
	if (str1.size() < str2.size())
	{
		swap(str1,str2);
	}
	reverse(str1.begin(),str1.end());
	reverse(str2.begin(),str2.end());
	int i = 0;
	while (str2[i] != '\0')
	{
		int a = str1[i] - '0' + str2[i] - '0';
		if (a < 10)
			str1[i] = a + '0';
		else
		{
			if (i == str1.size() - 1)
			{
				str1 += "0";
				str1[i] = '0' + a % 10;
				str1[i + 1] += 1;
				str1[i + 2] = '\0';
				break;
			}
			str1[i] = '0' + a % 10;
			str1[i + 1] += 1;
		}
		++i;
	}
	while (str1[i] != '\0')
	{
		int a = str1[i] - '0';
		if (a>9)
		{
			if (i == str1.size() - 1)
			{
				str1 += "0";
				str1[i] = '0' + a % 10;
				str1[i + 1] += 1;
				str1[i + 2] = '\0';
				break;
			}
			str1[i] = '0' + a % 10;
			str1[i + 1] += 1;
		}
		++i;
	}
	reverse(str1.begin(),str1.end());
	return str1;
}

int main()
{
	string addend;
	string augend;
	while (cin >> addend >> augend)
	{
		string str = Add(addend,augend);
		cout << str << endl;
	}
	return 0;
}