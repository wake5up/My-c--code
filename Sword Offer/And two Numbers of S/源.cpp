//和为S的两个数，若有多组，输出积为最小的数

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int len = array.size();
		if (len <= 0)
			return{};
		int left = 0;
		int right = len - 1;
		while (left <= right)
		{
			int num = array[left] + array[right];
			if (num>sum)
			{
				right--;
			}
			else if (num<sum)
			{
				left++;
			}
			else
			{
				return{ array[left], array[right] };
			}
		}
		return{};
	}
};