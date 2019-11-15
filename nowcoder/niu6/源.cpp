#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//#include <vector>
#include <string>

#if 0
//二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2
int main()
{
	int w, h;
	int count = 0;
	while (cin >> w >> h)
	{
		vector<vector<int>> a;
		a.resize(w);
		for (auto& e : a)
		{
			e.resize(h, 1);
		}
		for (int i = 0; i<w; i++)
		{
			for (int j = 0; j<h; j++)
			{
				if (a[i][j] == 1)
				{
					++count;

					if (i + 2<w)
						a[i + 2][j] = 0;
					if (j + 2<h)
						a[i][j + 2] = 0;
				}
             }
         }
         cout<<count;
     }
     return 0;                                                                                                     
 }
#endif

//把字符串转换为整数
#if 1
class Solution
{
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;
		int flag = 1;
		int sum=0;

		if (str[0] == '-')
		{
			flag = -1;
		}
		else if (str[0] == '+')
		{
			flag = 1;
		}
		for (int i=0; i < str.length(); i++)
		{
			if (str[i] <= '9'&&str[i] >= '0')
			{
				sum = sum * 10 + str[i] - '0';
			}
			else
			{
				sum = 0;
				break;
			}
				
		}
		cout << flag*sum;
	}
};
#endif

int main()
{
	Solution s;
	string str = "1234";
	s.StrToInt(str);
	return 0;
}