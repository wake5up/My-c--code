#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<cmath>
#include<string>

//16-->10
#if 0
int trans(char a)
{
	switch (a)
	{
	case'0':return 0;
	case'1':return 1;
	case'2':return 2;
	case'3':return 3; 
	case'4':return 4; 
	case'5':return 5; 
	case'6':return 6; 
	case'7':return 7;
	case'8':return 8;
	case'9':return 9;
	case'A':return 10;
	case'B':return 11;
	case'C':return 12;
	case'D':return 13;
	case'E':return 14;
	case'F':return 15;
	}
}
int main()
{
	string s16;
	cin >> s16;
	int len = s16.length();
	long long num=0;
	for (int i = 0; i < len; i++)
	{
		num += trans(s16[i])*pow(16,len-1-i);
	}
	cout << num;
	return 0;
}
#endif
#if 0
//10-->16
#include<cstdlib>
int main()
{
	long long n;
	int m;
	int k = 0;
	char str[100];
	cin >> n;
	if (n == 0)
	{
		cout << '0';
	}
	while (n>0)
	{
		m = n % 16;
		n /= 16;
		if (m > 9)
			str[k++] = 'A' + m-10;
		else
		str[k++] = '0' + m;
	}
	for (int i = k - 1; i >= 0; i--)
	{
		cout << str[i];
	}
	return 0;
}
#endif

