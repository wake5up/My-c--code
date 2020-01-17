#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#if 0
int main()
{
	int a = 1;
	int b;
	switch (a)
	{
	case 1: b = 30;
	case 2: b = 20;
	case 3: b = 16;
	default: b = 0;
	}
	cout << b;
	return 0;
}
#endif
//判断是否有重复的数字
#include <vector>
#include <algorithm>
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() <= 0)
			return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i<nums.size() - 1; i++)
		{
			if ((nums[i] ^ nums[i + 1]) == 0)
				return true;
		}
		return false;
	}
};
//长按键入
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		if (name.size()>typed.size())
			return false;
		int i = 0;
		int j = 0;
		for (i = 0, j = 0; i<name.size(), j<typed.size();)
		{
			if (name[i] == typed[j])
			{
				++i;
				++j;
			}
			else if (name[i - 1] == typed[j])
			{
				++j;
			}
			else if (name[i] != typed[j] && name[i - 1] != typed[j])
			{
				return false;
			}
		}
		return i == name.size() ? true : false;
	}
};

int main()
{
	//vector<int> v = {1,3,4};
	string s1 = "saeed";
	string s2 = "ssaaedd";
	Solution1 s;
	bool ret = s.isLongPressedName(s1, s2);
	return 0;
}