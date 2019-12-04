#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		int count = 0;
		for (int i = 0; i<n; i++)
		{
			if (gifts[i] == gifts[n / 2])
			{
				++count;
			}
		}
		if (count>n / 2)
			return gifts[n / 2];
	}
};
int main()
{
	vector<int> v = {2,2,2,23,4};
	Gift g;
	int ret=g.getValue(v, 5);
	cout << ret << endl;
	return 0;
}
#endif


