#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n>0)
		{
			if ((n & 1) == 1)
			{
				++count;
			}
			n = n >> 1;
		}
		cout << count << endl;
	}
	return 0;
}
