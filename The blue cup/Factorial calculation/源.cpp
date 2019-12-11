#include <iostream>
using namespace std;

//大数阶乘问题
int main()
{
	int arr[10000] = {1};
	int d = 1;
	int n;
	cin >> n;
	if (n<0 || n>1000)
		return 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		int jw = 0;
		int k;
		for (k = 0; k < d; k++)
		{
			temp = arr[k] * i + jw;
			arr[k] = temp % 10;
			jw = temp / 10;
		}
		while (jw)
		{
			arr[k]=jw % 10;
			k++;
			jw /= 10;
		}
		d = k;
	}
	for (int i = d - 1; i >= 0; i--)
	{
		cout << arr[i];
	}
	cout << endl;
	return 0;
}