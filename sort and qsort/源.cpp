#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<cstdlib>

#if 0
enum NumComp{ASE,DESC};

class compare
{
private:
	NumComp com;
public:
	compare(NumComp c)
		:com(c)
	{}
	bool operator()(int a, int b)
	{
		switch (com)
		{
		case ASE:
			return a < b;
		case DESC:
			return a > b;
		}
	}
};


int main()
{
	int n;
	cin >> n;
	int a[200];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n,compare(DESC));
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
#endif
#if 0
int compare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n;
	cin >> n;
	int a[200];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(int),compare);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
#endif

#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;// return *(int*)b-*(int*)a;
}

int  main()
{
	int a[10] = { 5, 6, 4, 3, 7, 0, 8, 9, 2, 1 };
	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " " << endl;
	return 0;
}