#define _CRT_SECURE_NO_WARNINGS 1

//最后一个单词的长度
#include <iostream>
#include <string>
using namespace std;

class Solution1 {
public:
	int lengthOfLastWord(string s) {
		if (s.empty())
			return 0;
		while (s.back() == ' ')
		{
				s.erase(s.end()-1);
		}
		if ((int)s.rfind(' ') == -1)
			return s.size();
		int len = s.size() - 1 - s.rfind(' ');
		return len;
	}
};

//nums1的数组和nums2的数组合并排序
#include <algorithm>
#include <vector>

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m, j = 0; i<m + n, j<n; ++i, ++j){
			nums1[i] = nums2[j];
		}
		sort(nums1.begin(), nums1.end());
	}
};

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int p = 0, i = 0, j = 0;
	vector<int> tmp(nums1.begin(), nums1.begin() + m);
	while (i<m&&j<n) 
		nums1[p++] = (tmp[i] < nums2[j]) ? tmp[i++] : nums2[j++];
	while (j<n) 
		nums1[p++] = nums2[j++];
	while (i<m) 
		nums1[p++] = tmp[i++];
}

int main()
{
	vector<int> v1 = {1,3,4};
	vector<int> v2 = {2,5};
	v1.resize(10);
	Solution s;
	s.merge(v1,4,v2,v2.size());
	return 0;
}