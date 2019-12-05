#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long n;
	long long count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int m = i;
		while (m>0)
		{
			int k = m % 10;
			if (k == 2)
			{
				count++;
				break;
			}
			else
			{
				m /= 10;
			}
		}
	}
	cout << n-count;
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
#include <string>
int main()
{
	string str;
	cin >> str;
	int i = 0;
	for (i = 0; i<str.length(); i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
		{
			cout << str[i];
			break;
		}
	}
	if (i==str.length())
		cout << "n";
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long a, b, c;
	cin >> a >> b >> c;
	long long count = 0;
	for (long long i = 1; i <= n; i++)
	{
		if (i%a != 0 && i%b != 0 && i%c != 0)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
#endif
#if 0 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int matrix[100][100] = { 0 };
	int row = 0;
	int col = 0;
	int start = 1;
	int m = M;
	int n = N;

	for (int count = 0; count < N / 2; count++)
	{
		for (; col < n - 1; col++) 
		{
			matrix[row][col] = start++;
		}
		for (; row < m - 1; row++) 
		{
			matrix[row][col] = start++;
		}
		for (col = n - 1; col > count; col--)
		{
			matrix[row][col] = start++;
		}
		for (row = m - 1; row > count; row--) 
		{
			matrix[row][col] = start++;
		}
		m--;
		n--;
		row++;
		start--;
	}
	if (N % 2 != 0) 
	{
		int  z = M - 2 * row;
		for (int i = 0; i< z; ++i)
			matrix[row++][col + 1] = ++start;
	}
	int a, b;
	cin >> a>> b;
	cout << matrix[a-1][b-1];

	return 0;
}
#endif

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#if 0


int main()
{
	int n, m;
	cin >> n >> m;
	char str[4][5];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>>str[i][j];
		}
	}
	int count = 0;
	int arr1[10] = {0};
	int arr2[10] = {0};
	int a=0, b=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == 'g')
			{
				arr1[a++] = i;
				arr2[b++] = j;
				count++;
			}
		}
	}

	int k;
	cin >> k;
	int i = 0, j = 0;
	for (i = 0, j = 0; i < count; i++, j++)
	{
		for (int f = 1; f <= k; f++)
		{
			if (arr2[j] - f >= 0)
				str[arr1[i]][arr2[j] - f] = 'g';
			if (arr2[j] + f < m)
				str[arr1[i]][arr2[j] + f] = 'g';
			if (arr1[i] - f >= 0)
				str[arr1[i] - f][arr2[j]] = 'g';
			if (arr1[i] + f < n)
				str[arr1[i] + f][arr2[j]] = 'g';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << str[i][j];
		}
		cout << endl;
	}
	return 0;
}
#endif
/*
int main()
{
	int n, m;
	cin >> n >> m;
	char str[4][5];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> str[i][j];
		}
	}
	int count = 0;
	int k;
	cin >> k;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == 'g')
			{
				for (int f = 1; f <= k; f++)
				{
					if (j - f >= 0)
						str[i][j - f] = 'g';
					if (j + f < m)
						str[i][j + f] = 'g';
					if (i - f >= 0)
						str[i - f][j] = 'g';
					if (i + f < n)
						str[i + f][j] = 'g';
				}
			}
		}
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << str[i][j];
		}
		cout << endl;
	}
	return 0;
}

*/
#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n, m,k;
	double num = 0;
	int array[10][3], a[10] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i][0] >> array[i][1] >> array[i][2];
	}
	cin >> k;
	double ree;
	for (int i = 0; i < n; ++i)
	{
		m = i + 1;
		if (array[i+1][2] > array[i][2])
		{
			m++;
		}
		if (a[i] != 0)
		{
			continue;
		}
		if (array[i + 1][2] <= array[i][2])
		{
			ree = sqrt(pow((array[i][0] - array[m][0]), 2) + pow((array[i][1] - array[m][1]), 2) + pow((array[i][2] - array[m][2]), 2));

			if (ree <= k)
			{
				num += ree;
				a[i]++;
			}
		}
	}
	printf("%.2f",num);
	return 0;
}
#endif

#include<cmath>

bool Issu(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
void fun(int n1, int n2)
{
	for (int i = n1; i <= n2; i++)
	{
		if (Issu(i))
		{
			cout << i << "=" << i << endl;
		}
		else
		{
			cout << i << "=";
			int num = i;
			int j = 2;
			while (num>1)
			{
				if (num%j == 0)
				{
					num /= j;
					cout << j;
					if (num != 1)
					{
						cout << "*";
					}
				}
				else
				{
					j++;
				}
			}
			cout << endl;
		}
	}
}

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	fun(n1, n2);
	return 0;
}