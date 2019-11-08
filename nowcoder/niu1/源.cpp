//组队竞赛，选择水平综合最大值

#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	int n;
	while (cin >> n)
	{
		int *arr = new int[3 * n];
		for (int i = 0; i<3 * n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + 3 * n);
		int j = 1;
		long sum = 0;
		while (j <= n)
		{
			sum += arr[3 * n - 2 * j];
			j++;
		}
		cout << sum << endl;
	}
	return 0;
}

//删除公共字符
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	int arr[256] = { 0 };
	for (int i = 0; i<str2.size(); i++)
	{
		++arr[str2[i]];
	}
	string ret;
	for (int i = 0; i<str1.size(); i++)
	{
		if (arr[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret;
	return 0;
}
