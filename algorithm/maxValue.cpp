//礼物的最大价值

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int n = grid[0].size();
		int m = grid.size();
		vector<int> v(n+1,0);
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				v[j+1]=max(v[j+1],v[j])+grid[i][j];
			}
		}
		return v[n];
	}
};

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int n = grid[0].size();
		int m = grid.size();
		vector<int> v(n);
		for (int i = 0; i<m; i++)
		{
			int up = 0;
			int left = 0;
			for (int j = 0; j<n; j++)
			{
				if (i>0)
					up = v[j];
				if (j>0)
					left = v[j-1];
				v[j] = std::max(up, left) + grid[i][j];
			}
		}
		return v[n-1];
	}
};