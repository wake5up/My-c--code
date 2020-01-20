#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <cstdio>

int main()
{
	//char *p = "abcdefgh", *r;
	//long *q;
	//q = (long*)p;
	//q++;
	//r = (char*)q;
	//printf("%s\n", r);
	char str[] = "ABCD", *p = str;
	printf("%d\n", *(p + 4));
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() <= 0)
			return -1;
		for (int i = 0; i<nums.size(); i++)
		{
			int ret = Solution::Find(nums, i);
			if (ret>=0)
				return ret;
		}
		return -1;
	}
	int Find(vector<int> nums, int index)
	{
		int lsum = 0;
		int rsum = 0;
		if (index == 0)
			lsum = 0;
		if (index == nums.size() - 1)
			rsum = 0;
		for (int i = 0; i<index; i++)
		{
			lsum += nums[i];
		}
		for (int i = index + 1; i<nums.size(); i++)
		{
			rsum += nums[i];
		}
		if (lsum == rsum)
			return index;
		else
			return -1;
	}
};
int main()
{
	vector<int> v = {1,-1,9,0,1,1};
	Solution s;
	int ret=s.pivotIndex(v);
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

char* returnValue()
{
    char* str = "HelloJacky";
    return str;
}
int main()
{
	char* ret = returnValue();
	cout << ret;
	return 0;
}
#endif
#if 1
#include <cstdio>
#include <iostream>
using namespace std;

int returnValue(int a,int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int ret = returnValue(4,5);
	cout << ret<<endl;
	return 0;
}
#endif
