#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		int LSize = num1.size();
		int RSize = num2.size();
		if (LSize < RSize)
		{
			num1.swap(num2);
			swap(LSize, RSize);
		}
		string strRet(LSize+1,'0');//相加之后的结果
		char offset = 0;//进位数字
		for (int LIdx = num1.size() - 1, RIdx = num2.size() - 1; LIdx >= 0; LIdx--, RIdx--)
		{
			char cRet = num1[LIdx] - '0';//把最后一位字符转换为数字
			if (RIdx >= 0)
			{
				cRet += num2[RIdx] - '0';
			}
			cRet += offset;
			offset = 0;
			if (cRet >= 10)
			{
				offset = 1;
				cRet -= 10;
			}
			strRet[LIdx + 1] += cRet;
		}
		if (offset == 1)
			strRet[0] += 1;
		else
			strRet.erase(strRet.begin());
		return strRet;
	}
};

int main()
{
	Solution s;
	cout << s.addStrings("1111111111111111", "99999999999999999") << endl;
	return 0;
}