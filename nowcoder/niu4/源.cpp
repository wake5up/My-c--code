#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include <string>

#if 0
//计算糖果
int main()
{
	int a, b, c, d;
	int A, B, C=0;
	bool flag = true;
	while (cin >> a >> b >> c >> d)
	{
		for (int i = -30; i <= 30; i++)
		{
			for (int j = -30; j <= 30; j++)
			{
				if (i - j == a&&i + j == c)
				{
					A = i;
					B = j;
				}
			}
		}
		for (int i = -30; i <= 30; i++)
		{
			if (B - i == b&&B + i == d)
			{
				C = i;
				flag = false;
			}
		}
		if (flag)
		{
			cout << "No";
		}
		else
			cout << A << " " << B << " " << C;
	}
	return 0;
}
#endif

#if 0
//进制转换，十进制转N进制
int main()
{
	int M, N;
	int arr[100] = { 0 };
	char str[100] = { 0 };
	while (cin >> M >> N)
	{
		if (M<0)
		{
			M = -M;
			cout << "-";
		}
		if (M == 0)
		{
			cout << 0;
			break;
		}
		int i = 0;
		if (N <= 10)
		{
			while (M>0)
			{
				arr[i++] = M%N;
				M /= N;
			}
			for (i = i - 1; i >= 0; i--)
				cout << arr[i];
		}
		else
		{
			int j = 0;
			while (M>0)
			{
				int k = 0;
				k = M%N;
				if (k<10)
					str[j++] = '0' + k;
				else
					str[j++] = 'A' + k - 10;

				M /= N;

			}
			for (j = j - 1; j >= 0; j--)
			{
				cout << str[j];
			}
		}
	}
	return 0;
}
#endif

#if 0
//大佬的

int main(){
	string s = "", table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m)
	{
		if (m<0)
		{
			m = -m;
			cout << "-";
		}
		if (m == 0)
		{
			cout << 0;
			break;
		}
		s = table[m%n] + s;
		m /= n;
	}
	cout << s << endl;
	return 0;
}
#endif
