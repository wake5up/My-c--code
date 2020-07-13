//芯片测试
//每个芯片都能用来测试其他芯片。用好芯片测试其他芯片时，能正确给出被测试芯片是好还是坏。而用坏芯片测试其他芯片时，会随机给出好或是坏的测试结果（即此结果与被测试芯片实际的好坏无关）。
//给出所有芯片的测试结果，问哪些芯片是好芯片。

#include <iostream>

using namespace std;

int main()
{
	int array[21][21];
	int n,t;
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){	
			cin>>t;
			array[i][j] = t;
		} 
	}
	for(int j = 1;j <= n;j++){
		int ts = 0;
		for(int i = 1;i <= n;i++){
			ts += array[i][j];
		}
		if(ts > n / 2){
			if(j==n)
			{
				cout<<j;
			}
			else
				cout<<j<<" ";
		}
	}
	return 0;
}
