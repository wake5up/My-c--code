#define _CRT_SECURE_NO_WARNINGS 1

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写.注意：如果测试用例
//出现错误：OP这个情况一定注意，这是0P

#include <iostream>
#include <string>
using namespace std;

class Solution1 {
public:
	bool isPalindrome(string s) {
		int i = 0;
		int j = s.size() - 1;
		while (i<j)
		{
			while ((s[i]<'0'||s[i]>'9'&&s[i]<'A' || s[i]>'Z'&&s[i]<'a' || s[i]>'z') && i<s.size())
			{
				i++;
				if (i == s.size())
					return true;
			}
			while ((s[j]<'0' || s[j]>'9'&&s[j]<'A' || s[j]>'Z'&&s[j]<'a' || s[j]>'z') && j >= 0)
			{
				j--;
			}
			if (!CompIsalin(s[i], s[j]))
				return false;
			else
			{
				i++;
				j--;
			}
		}
		return true;
	}
	bool CompIsalin(char ch1, char ch2)
	{
		if (ch1 >= 'A'&&ch1 <= 'Z' || ch1 >= 'a'&&ch1 <= 'z')
		{
			if (ch2 == ch1 || ch2 == ch1 - 32 || ch2 == ch1 + 32)
				return true;
		}
		if (ch1 >= '0'&&ch1 <= '9')
		{
			if (ch2 == ch1)
				return true;
		}
		return false;
	}
};
//给定一组字符，使用原地算法将其压缩。压缩后的长度必须始终小于或等于原数组长度。数组的每个元素应该
//是长度为1 的字符（不是 int 整数类型）。在完成原地修改输入数组后，返回数组的新长度
#include <vector>
class Solution {
public:
	int compress(vector<char>& chars) {
		auto it = chars.begin();
		int count = 1;
		while (it != chars.end())
		{
			++it;
			if (it != chars.end()&&*it != *(it - 1))
			{
				continue;
			}
			if (it != chars.end()&&*it >= '0'&&*it <= '9')
				continue;
			while (it != chars.end()&& *it == *(it - 1) )
			{
				it = chars.erase(it);
				count++;
			}
			if (count == 1)
				continue;
			else
			{
				int k = 1;
				while (k)
				{
					k = count % 10;
					it = chars.insert(it, '0' + k);
					count = count / 10;
					k = count;
				}
				count = 1;
			}
		}
		return chars.size();
	}
};

int main()
{
	//string s1 = "1b1";
	vector<char> v = {'a','a','a','a'};
	Solution s;
	s.compress(v);
	return 0;
}