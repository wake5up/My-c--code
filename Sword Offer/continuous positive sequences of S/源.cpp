//和为S的连续正数序列

class Solution {
public:
    vector<vector<int>> v;
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum<3)
			return{};
		int left = 1;
		int right = 2;
		int mid = sum >> 1;
		int num = left + right;
		int i = -1;
		while (left <= mid)
		{
			if (num == sum)
			{
				++i;
				PushNum(i, left, right);
			}
			while (num > sum&&left<=mid)
			{
				num -= left;
				left++;
				if (num == sum)
				{
					++i;
					PushNum(i,left,right);
				}
			}
			right++;
			num += right;
		}
		return v;
	}
	void PushNum(int i, int left, int right)
	{
		v.push_back(vector<int>());
		for (int j = left; j <= right; j++)
		{
			v[i].push_back(j);
		}
	}
};