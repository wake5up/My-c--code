#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//实现函数 ToLowerCase() ，该函数接收一个字符串参数 str ，并将该字符串中的大写字母转换成小写字母，
//之后返回新的字符串

#if 0
class Solution {
public:
	string toLowerCase(string str) {
		int i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				str[i] += 'a' - 'A';
			}
			++i;
		}
		return str;
	}
};
#endif
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
#if 0
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		for (int i = 0; i<k; i++)
		{
			nums.insert(nums.begin(), nums.back());
			nums.erase(nums.end() - 1);
		}
	}
};
#endif