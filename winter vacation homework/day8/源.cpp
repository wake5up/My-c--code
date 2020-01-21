#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位， 数
//组中每个元素只存储单个数字。
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int index = digits.size() - 1;
		int jw=1;
		while (jw)
		{
			jw = 0;

			digits[index]++;
			if (digits[0]>9)
			{
				digits.resize(digits.size() + 1);
				for (int i = digits.size()-1; i > 1; i--)
				{
					digits[i] = digits[i - 1];
				}
				digits[1] = digits[0] & 1;
				digits[0] /= 10;
				break;
			}
			if (digits[index]>9)
			{
				jw = digits[index]/10;
				digits[index] &= 1;
				index--;
			}
		}
		return digits;
	}
};

//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		if (nums.size() == 1)
		{
			return nums[0];
		}
		sort(nums.begin(), nums.end());
		int count = 1;
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] == nums[i + 1])
				continue;
			count++;
			if (count == 3)
				return nums[i];
		}
		return nums[nums.size() - 1];
	}
};



int main()
{
	vector<int> v = {9,9,9,9};
	Solution s;
	vector<int> v1=s.plusOne(v);
	return 0;
}


