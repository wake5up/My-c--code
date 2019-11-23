#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#if 0
int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '"')
			{
				++i;
				while (str[i] != '"')
				{
					++i;
				}
			}
			if (str[i] == ' ')
				count++;
			++i;
		}
		cout << count+1 << endl;
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] != ' ')
			{
				if (str[i] == '"')
				{
					++i;
					while (str[i] != '"')
					{
						cout << str[i];
						++i;
					}
					++i;
				}
				else
				{
					cout << str[i];
					++i;
				}	
			}
			else 
			{
				cout << endl;
				++i;
			}
		}
	}
	return 0;
}
#endif

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		int count = 0;
		bool flag = true;
		while (1)
		{
			if (M<N + N / 2)
			{
				int n = N;
				int i = 3;
				for (i = 3; i<n; i++)
				{
					if (n%i == 0 && n + i == M)
					{
						++count;
						break;
					}
				}
				if (i == n)
				{
					flag = false;
					break;
				}
				break;
			}
			else
			{
				N += N / 2;
				++count;
			}
		}
		if (flag)
			cout << count;
		else
			cout << "-1";
	}
	return 0;
}