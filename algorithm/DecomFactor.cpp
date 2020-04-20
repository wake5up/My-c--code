// 分解质因数
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout <<n<< " = ";
		for (int i = 2; i <= sqrt(n) && n != 1; i++)
		{
			while (n%i == 0)
			{
				cout << i;
				n /= i;
				if (n != 1)
					cout << " * ";
				else
					cout << endl;
			}
		}
		if (n != 1)
			cout << n << endl;
	}
	return 0;
}