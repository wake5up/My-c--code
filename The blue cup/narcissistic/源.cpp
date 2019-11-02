#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
int main()
{
	
	for (int a = 1; a <= 9;a++)
	for (int b = 0; b <= 9;b++)
	for (int c = 0; c <= 9;c++)
	{
		if (a * 100 + b * 10 + c == a*a*a + b*b*b + c*c*c)
		{
			cout << a * 100 + b * 10 + c<<endl;
		}
	}
	return 0;
}
#endif

#if 0 
int main()
{
	int arr[34][34] = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for (int i = 2; i < n; i++)
	for (int j = 1; j < i; j++)
	{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif

#if 0
bool find(int (*arr)[4], int row, int col,int n)
{
	if (arr!=nullptr&&row>0&&col>0)
	{
		for (int i = 0; i < row;)
		{
			for (int j = col - 1; j >= 0;)
			{
				if (arr[i][j] < n)
					i++;
				else if (arr[i][j]>n)
					j--;
				else
					return true;
			}
		}
	}
	return false;
}

int main()
{
	int arr[][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	int n;
	cin >> n;
	bool ret = find(arr,4,4,n);
	cout <<boolalpha << ret << endl;
	return 0;
}
#endif

#if 0
int find(int* arr, int num, int n)
{
	for (int i = 0; i<n; i++)
	{
		if (arr[i] == num)
		{
			return i + 1;
		}
	}
	return -1;
}
int main()
{
	int n;
	int arr[1000];
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int num = 0;
	cin >> num;
	int ret = find(arr, num, n);
	cout << ret;
	return 0;
}
#endif

#if 0
long long Max(long long *arr, int n)
{
	long long max = arr[0];
	for (int i = 1; i < n; i++)
	{
		max>arr[i] ? max = max : max = arr[i];
	}
	return max;
}

long long Min(long long *arr, int n)
{
	long long min = arr[0];
	for (int i = 1; i < n; i++)
	{
		min < arr[i] ? min = min : min = arr[i];
	}
	return min;
}

long long Add(long long *arr, int n)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	long long arr[10000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ret1 = Max(arr, n);
	int ret2 = Min(arr,n);
	long long ret3 = Add(arr,n);
	cout << ret1 << endl << ret2 << endl << ret3 << endl;
	return 0;
}
#endif
