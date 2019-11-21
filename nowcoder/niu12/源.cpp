#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <cmath>

#if 0
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		int arr1[32];
		int k1 = 0;
		while (n>0)
		{
			arr1[k1++] = n % 2;
			n /= 2;
		}
		int arr2[32];
		int k2 = 0;
		while (m>0)
		{
			arr2[k2++] = m % 2;
			m /= 2;
		}
		if (k2<k1)
		{
			for (int c = i; c>=j; c--)
			{
				if (arr1[c] != 0)
				{
					return 0;
				}		
			}
			for (int a = j, b = 0; a <= i; a++, b++)
			{
				arr1[a] = arr2[b];
			}
			int sum = 0;
			for (int i = k1 - 1; i >= 0; i--)
			{
				sum +=pow(2,i)*arr1[i];
			}
			return sum;
		}
	}
};
int main()
{
	BinInsert b;
	int ret=b.binInsert(1024, 19, 2, 6);
	cout << ret;
	return 0;
}
#endif

#if 0
//´óÀÐ´úÂë
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		return n + (m << j);//return n | (m<<j);
	}
};
#endif

bool IsSu(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int num1 = 0;
		int num = 10000;
		int a1, a2, b1, b2;
		for (int i = 1; i<=n/2; i++)
		{
			if (IsSu(i))
			{
				if (IsSu(n - i))
				{
					num1 = n - i - i;
					a1 = i;
					b1 = n - i;
					if (num1 < num)
					{
						num = num1;
						a2 = a1;
						b2 = b1;
					}
				}
				
			}
			else
				continue;
		}
		cout << a2 << endl << b2;
	}
	return 0;
}