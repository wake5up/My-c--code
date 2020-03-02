//翻转单词的顺序列

class Solution {
public:
	string ReverseSentence(string str) {
		int len = str.size();
		if (len <= 0)
			return "";
		Reverse(str, 0, len - 1);
		int i = 0;
		int s = 0, e = 0;
		while (i<len)
		{
			if (str[i] == ' ')
			{
				e = i;
				Reverse(str, s, e - 1);
				s = e + 1;
			}
			++i;			
		}
		Reverse(str, s, i-1);
		return str;
	}
	void Reverse(string &str, int start, int end)
	{
		while (start<end)
			swap(str[start++], str[end--]);
	}
};