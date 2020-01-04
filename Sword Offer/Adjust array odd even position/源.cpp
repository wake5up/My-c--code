#include <iostream>
#include <vector>
using namespace std;

//调整数组顺序使奇数位于偶数前面
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty())
			return;
		int left = 0;
		int right = array.size() - 1;
		while (left<right)
		{
			while (left<right&&(array[left] & 0x1) == 1)
				++left;
			while (left<right&&(array[right] & 0x1) != 1)
				--right;
			if (left<right)
			{
				int temp = array[left];
				array[left] = array[right];
				array[right] = temp;
			}
		}
	}
};
//调整数组顺序使奇数位于偶数前面
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> result;
		for (int i = 0; i<array.size(); i++)
		{
			if (array[i] % 2 == 1)
			{
				result.push_back(array[i]);
			}
		}
		for (int i = 0; i<array.size(); i++)
		{
			if ((array[i] & 0x1) == 0)
				result.push_back(array[i]);
		}
		array = result;
	}
};

int main()
{
	vector<int> v = {1,2,3,4,5,6};
	Solution s;
	s.reOrderArray(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}