//给定一个按非递减顺序排序的整数数组 A ，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		for (int i = 0; i<A.size(); i++)
		{
			A[i] *= A[i];
		}
		sort(A.begin(), A.end());
		return A;
	}
};
//仅仅反转字母

class Solution {
public:
	string reverseOnlyLetters(string S) {
		int i = 0;
		for (i = 0; i < S.size(); ++i)
		{
			if (S[i] >= 'A'&&S[i] <= 'Z' || S[i] >= 'a'&&S[i] <= 'z')
				break;
		}
		if (i == S.size())
			return S;
		int left = 0;
		int right = S.size() - 1;
		while (left<right)
		{
			while (!(S[left] >= 'A'&&S[left] <= 'Z' || S[left] >= 'a'&&S[left] <= 'z') && left<right)
				left++;
			while (!(S[right] >= 'A'&&S[right] <= 'Z' || S[right] >= 'a'&&S[right] <= 'z') && left<right)
				right--;
			Solution::Swap(S[left], S[right]);
			++left;
			--right;
		}
		return S;
	}
	void Swap(char &left, char &right)
	{
		char temp = left;
		left = right;
		right = temp;
	}
};
