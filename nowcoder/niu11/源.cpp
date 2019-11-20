#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//二叉树中寻找最近的共同祖先
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (1)
		{
			if (a>b)
				a /= 2;
			else if (a<b)
				b /= 2;
			else
				return a;
		}

	}
};
#endif

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count1 = 0;
		int count = 0;
		while (n != 0)
		{
			if ((n & 1) == 1)
				++count1;
			else
				count1 = 0;
			if (count1>count)
			{
				count = count1;
			}
			n = n >> 1;
		}
		cout << count<<endl;
	}
	return 0;
}