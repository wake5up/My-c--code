#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#if 0
int main()
{
	string str;
	while (getline(cin, str))
	{
		int count1 = 0;
		int count = 0;
		int a = 0;
		for (int i = 0; i<=str.size(); i++)
		{
			if (str[i] <= '9'&&str[i] >= '0')
			{
				++count1;
			}
			else
			{
				if (count<count1)
				{
					count = count1;
					a = i - count;
				}
				count1 = 0;
			}
		}
		for (int i = a; i<a+count; i++)
		{
			cout << str[i];
		}
	}
	return 0;
}
#endif

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		sort(numbers.begin(), numbers.end());
		int mid = numbers[numbers.size() / 2];
		int count = 0;
		for (int i = 0; i<numbers.size(); i++)
		{
			if (numbers[i] == mid)
			{
				count++;
			}
		}
		return (count>numbers.size() / 2) ? mid : 0;
	}
};