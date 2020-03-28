//翻转单词顺序
class Solution {
public:
	string reverseWords(string s) {
		if (s.size() <= 0)
			return "";
		Reverse(s, 0, s.size() - 1);
		int i = 0;
		while (s[i] == ' ')
		{
			s.erase(i, 1);
		}
		int j = s.size() - 1;
		while (s[j] == ' ')
		{
			s.erase(j, 1);
			j--;
		}
		int left = 0;
		for (int i = 0; i<s.size();)
		{
			while (i<s.size()&&s[i] != ' ')
				i++;
			if (i == s.size())
				break;
			while (s[i + 1] == ' '&&s[i] == ' ')
				s.erase(i, 1);
			Reverse(s, left, i-1);
			left = ++i;
		}
		Reverse(s, left, s.size() - 1);
		return s;
	}
	void Reverse(string& s, int l, int r)
	{
		while (l <= r)
		{
			swap(s[l], s[r]);
			l++;
			r--;
		}
	}
};