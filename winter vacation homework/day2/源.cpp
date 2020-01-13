//给定一个数组 nums 和一个值 val ，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		auto it = nums.begin();
		while (it != nums.end())
		{
			if (*it == val)
			{
				it = nums.erase(it);
			}
			else
				++it;
		}
		return nums.size();
	}
};

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它
//将会被按顺序插入的位置, 你可以假设数组中无重复元素.

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = 0;
		for (i = 0; i<nums.size(); i++)
		{
			if (nums[i] >= target)
				return i;
		}
		return i;
	}
};