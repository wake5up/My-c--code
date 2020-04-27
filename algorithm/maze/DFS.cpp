//场景：最短路径的经过哪些点（描绘出来）
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int xx[] = { 0, 1, 0, -1 };
int yy[] = { 1, 0, -1, 0 };

vector<vector<int>> arr;//走过的路径
vector<vector<int>> arrMin;//最短路径
bool flag = false;

bool DFS(vector<vector<char> >& v, int& x, int& y, int& step, int& n, int& m, int& Min)//深度优先算法
{
	if (x == n - 1 && y == m - 1)
	{
		if (step < Min)
		{
			Min = step;
			arrMin = arr;
			flag = true;
		}	
	}
	for (int i = 0; i<4; i++)
	{
		int x1 = x + xx[i];
		int y1 = y + yy[i];
		if (x1 >= 0 && x1<n&&y1 >= 0 && y1<m&& v[x1][y1] == '0')
		{
			int step1 = step + 1;
			v[x1][y1] = '1';
			arr.push_back({x1,y1});
			DFS(v, x1, y1, step1, n, m, Min);
			v[x1][y1] = '0';
			arr.pop_back();
		}
	}
	return flag;
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
		int Min = 9999999;
		int i = 0, j = 0, k = 0;
		bool ret=DFS(v, i, j, k, n, m, Min);
		if (ret)
		{
			cout << Min << endl;
			for (auto e : arrMin)
				cout << e[0] + 1 << "," << e[1] + 1 << endl;
		}
		else
			cout << "没有到达目的地" << endl;
	}
	return 0;
}