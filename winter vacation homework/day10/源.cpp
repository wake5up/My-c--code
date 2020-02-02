#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <cstdio>

int a, b;
void fun()
{
	a = 100;
	b = 200;
} 
int main()
{
	int a = 5, b = 7;
	fun();
	printf("% d % d / n", a, b);
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;
class Solution1 {
public:
	int myAtoi(string str) {
		int i = 0;
		int flag = 1;
		int num = 0;
		while (str[i] == ' ')
		{
			++i;
		}
		while (str[i] != '\0')
		{
			if (str[i] == '-' || str[i] == '+')
			{
				if (str[i] == '-')
				{
					flag = -1;
				}
				++i;
				if (str[i] == '-' || str[i] == '+')
					return 0;
			}
			if (str[i] >= '0'&&str[i] <= '9')
			{
				num = num * 10 + (str[i] - '0');
				if (flag*num < INT_MIN / 10 && str[i + 1] >= '0'&&str[i + 1] <= '9')
					return INT_MIN;
				++i;
			}
			else
			{
				break;
			}
		}
		return flag*num;
	}
};

class Solution2 {
public:
	int myAtoi(string str) 
	{
		int res = 0;
		int i = 0;
		int flag = 1;
		// 1. 检查空格
		while (str[i] == ' ') 
		{ 
			i++;
		}
		// 2. 检查符号
		if (str[i] == '-') 
		{ 
			flag = -1; 
		}
		if (str[i] == '+' || str[i] == '-') 
		{ 
			i++; 
		}
		// 3. 计算数字
		while (i < str.size() && isdigit(str[i])) 
		{
			int r = str[i] - '0';
			// ------ 4. 处理溢出，这是关键步骤 ------
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
			{
				return flag > 0 ? INT_MAX : INT_MIN;
			}
			res = res * 10 + r;
			i++;
		}
		return flag > 0 ? res : -res;
	}
};
#include <vector>
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() <= 0 || nums.front() > target || nums.back() < target)
			return{-1,-1};
		vector<int> v;
		int i = 0;
		int j = nums.size() - 1;
		int mid = 0;
		while (i<=j)
		{
			mid = (i + j) / 2;
			if (nums[mid]>target)
			{
				j = mid-1;
			}
			else if (nums[mid]<target)
			{
				i = mid+1;
			}
			else
			{
				i = mid;
				j = mid;
				while (i >= 0&&nums[i] == target)
				{
					i--;
				}
				v.push_back(i+1);
				while (j<nums.size()&&nums[j] == target)
				{
					j++;
				}
				v.push_back(j-1);
				break;
			}
		}
		if (v.size() == 0)
			return{ -1, -1 };
		return v;
	}
};

int main()
{
	vector<int> v = { 1};
	Solution s1;
	int k = 1;
	vector<int> ret=s1.searchRange(v,k);
	return 0;
}