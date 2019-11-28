#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		int arr[100];
		arr[1] = 1;
		arr[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		cout << arr[n] << endl;
	}
	return 0;
}
#endif


//Í¨Åä·ûÌæ»»
#include <iostream>
#include <string>
using namespace std;

bool IsTrue(string str1, string str2)
{
	int i = 0;
	int j = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[j])
		{
			++i;
			++j;
		}
		else if (str1[i] == '?')
		{
			if ((str2[j] >= '0'&&str2[j] <= '9') || (str2[j] >= 'A'&&str2[j] <= 'Z') || (str2[j] >= 'a'&&str2[j] <= 'z'))
			{
				++j;
				++i;
			}
			else
			{
				return false;
			}
		}
		else if (str1[i] == '*')
		{
			int n = 9;
			while (n--)
			{
				if ((str2[j] >= '0'&&str2[j] <= '9') || (str2[j] >= 'A'&&str2[j] <= 'Z') || (str2[j] >= 'a'&&str2[j] <= 'z'))
				{
					if (str2[j] == str1[i + 1])
					{
						if (str2[j] == '\0')
						{
							++i;
							break;
						}
						i += 2;
						++j;
						break;
					}
					++j;
				}
				else if (str2[j] == str1[i + 1])
				{
					if (str2[j] == '\0')
					{
						++i;
						break;
					}
					i += 2;
					++j;
					break;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		bool ret = IsTrue(str1,str2);
		cout << boolalpha << ret << endl;
	}
	return 0;
}