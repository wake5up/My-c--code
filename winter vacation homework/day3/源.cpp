#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

class Solution1 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		for (int i = 0; i<ransomNote.size(); i++)
		{
			bool flag = false;
			auto it = magazine.begin();
			while (it != magazine.end())
			{
				if (ransomNote[i] != *it)
				{
					it++;
					continue;
				}
				else
				{
					magazine.erase(it);
					it = magazine.begin();
					break;
				}
			}
			if (it == magazine.end())
				return flag;
		}
		return true;
	}
};
#include <cstdlib>
#include <cstring>
#include <cstring>
class Solution {
public:
	bool isPalindrome(int x) {
		char str[32];
		Solution::itoa(x, str);
		int i = 0;
		int j = strlen(str) - 1;
		while (i<j)
		{
			if (str[i] != str[j])
			{
				return false;
			}
			++i;
			--j;
		}
		return true;
	}
	void itoa(int x, char* str)
	{
		int i = 0;
		while (x>0)
		{
			str[i++]=x % 10+'0';
			x /= 10;
		}
		str[i] = '\0';
		reverse(str,str+strlen(str));
	}
};
int main()
{
	string str1 = "djfjfhjf";
	string str2 = "aaigcbiafifghhdihcfdjjej";
	Solution s;
	bool ret=s.isPalindrome(10);
	return 0;
}