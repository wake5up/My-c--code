//迷宫问题
#if 0
//第一种方法，效率稍微有点低
//使用场景最短路径长度
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point
{
	int x;
	int y;
	int step;
};
int xx[] = { 0, 1, 0, -1 };
int yy[] = { 1, 0, -1, 0 };

queue<point> q;

bool BFS(vector<vector<char> >& v, int n, int m)//深度搜索
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		if (x == n - 1 && y == m - 1)//判断条件位置1
		{
			return true;
		}
		for (int i = 0; i<4; i++)
		{
			int x1 = x + xx[i];
			int y1 = y + yy[i];
			if (x1 >= 0 && x1<n&&y1 >= 0 && y1<m&&v[x1][y1] == '0')
			{
				point p;
				p.x = x1;
				p.y = y1;
				p.step = q.front().step + 1;
				q.push(p);
				v[x1][y1] = '1';
			}
		}
		q.pop();
	}
	return false;
}

int main()
{
	int n, m;
	if (cin >> n >> m)
	{
		vector<vector<char> > v(n, vector<char>(m));
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin >> v[i][j];
			}
		}
		point start;
		start.x = 0;
		start.y = 0;
		start.step = 0;
		q.push(start);
		v[0][0] = '1';
		bool ret = BFS(v, n, m);
		if (ret)
			cout << q.front().step;
		else
			cout << "没有到达目的地" << endl;
	}
	return 0;
}
#endif 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point
{
	int x;
	int y;
	int step;
};
int xx[] = { 0, 1, 0, -1 };
int yy[] = { 1, 0, -1, 0 };

queue<point> q;

bool BFS(vector<vector<char> >& v, int n, int m)
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		
		for (int i = 0; i<4; i++)
		{
			int x1 = x + xx[i];
			int y1 = y + yy[i];
			if (x1 >= 0 && x1<n&&y1 >= 0 && y1<m&&v[x1][y1] == '0')
			{
				point p;
				p.x = x1;
				p.y = y1;
				p.step = q.front().step + 1;
				q.push(p);
				v[x1][y1] = '1';
				if (x1 == n - 1 && y1 == m - 1)//判断条件位置二
				{
					return true;
				}
			}
		}
		q.pop();
	}
	return false;
}

int main()
{
	int n, m;
	if (cin >> n >> m)
	{
		if (n == 1 && m == 1)
		{
			cout << "1" << endl;
			return 0;
		}
		vector<vector<char> > v(n, vector<char>(m));
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin >> v[i][j];
			}
		}
		point start;
		start.x = 0;
		start.y = 0;
		start.step = 0;
		q.push(start);
		v[0][0] = '1';
		bool ret = BFS(v, n, m);
		if (ret)
			cout << q.back().step;
		else
			cout << "没有到达目的地" << endl;
	}
	return 0;
}