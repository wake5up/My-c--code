#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

int IsTrueDay(int year, int month)
{
	int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		arr[2] += 1;
	}
	return arr[month];
}

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int count = 0;
		if (year>0&&month<13 && month>0 && day > 0 && day <= IsTrueDay(year, month))
		{
			for (int i = 1; i < month; i++)
			{
				count += IsTrueDay(year, i);
			}
			count += day;
			cout << count<<endl;
		}
		else
			cout << "-1"<<endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nums[1000];

// 思路：DFS生成全组合，同时注意剪枝、避免重复组合
int findall(int nums[], int index, long sum, long multi) {
	int count = 0;
	for (int i = index; i<n; i++) {
		sum += nums[i];
		multi *= nums[i];
		if (sum > multi)
			count += 1 + findall(nums, i + 1, sum, multi);
		else if (nums[i] == 1)
			count += findall(nums, i + 1, sum, multi);
		else
			break;
		sum -= nums[i];
		multi /= nums[i];
		// 跳过相等的元素，避免重复组合
		while (i<n - 1 && nums[i] == nums[i + 1])
			i++;
	}
	return count;
}

int main(int argc, char* argv[])
{
	while (cin >> n) {
		for (int i = 0; i<n; i++)
			cin >> nums[i];

		// 从小到大排序
		sort(nums,nums+n);
		int num = findall(nums, 0, 0, 1);
		cout << num << endl;
	}

	return 0;
}