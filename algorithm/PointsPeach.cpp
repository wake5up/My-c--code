#include<iostream>
#include<cmath>
using namespace std;

//猴子分桃
//分五堆，会剩一个，然后拿一堆，n为有几个猴子，
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else
		{
			cout << (long long)pow(5, n) - 4 << " " << (long long)pow(4, n) + n - 4 << endl;//桃子总个数，最后剩多少个
		}
	}
	return 0;
}