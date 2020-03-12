//最长递增子序列长度

class AscentSequence {
public:
	int findLongest(vector<int> A, int n) {
		vector<int> dp;
		dp.resize(n, 1);
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<i; j++)
			{
				if (A[j] <= A[i])
				{
					if (dp[j]>=dp[i])
					{
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
		sort(dp.begin(), dp.end());
		return dp[n - 1];
	}
};

