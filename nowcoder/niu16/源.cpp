#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;

		for (int i = 3; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j<i; j++)
			{
				if (i%j == 0)
				{
					sum += j;
				}
			}
			if (sum == i)
				++count;
		}
		cout << count << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line.find("joker JOKER") != -1)
		{
			cout << "joker JOKER";
		}
		else
		{
			int index = line.find('-');
			string str1 = line.substr(0, index);
			string str2 = line.substr(index + 1);
			int c1 = count(str1.begin(), str1.end(), ' ');
			int c2 = count(str2.begin(), str2.end(), ' ');
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				if (str.find(first1) > str.find(first2))
					cout << str1;
				else
					cout << str2;
			}
			else
			{
				if (c1 == 3)
					cout << str1 << endl;
				else if (c2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}