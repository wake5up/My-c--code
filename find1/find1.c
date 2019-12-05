#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

bool find(int *arr, int row, int col, int n)
{
	bool flag = false;
	if (arr != nullptr&&row > 0 && col > 0)
	{
		int _row = 0;
		int _col = col - 1;
		while (_col>0&&_row<row)
		{
			if (arr[_row*col + _col] > n)
			{
				_col--;
			}
			else if (arr[_row*col + _col] < n)
			{
				_row++;
			}
			else
			{
				flag = true;
				return flag;
			}
		}
	}
	return flag;
}

int main()
{
	int arr[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	bool ret=find((int *)arr, 4, 4, 7);
	cout << boolalpha >> ret;
	return 0;
}
