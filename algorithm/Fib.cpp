//斐波那契凤尾
#include <iostream>
using namespace std;

int main()
{
    int arr[100000];
    arr[0]=1;
    arr[1]=2;
    for(int i=2;i<100000;i++)//空间换时间
    {
        arr[i]=(arr[i-1]+arr[i-2])%1000000;
    }
    int n;
    while(cin>>n)//时间复杂度从用例开始
    {
        printf(n<29?"%d\n":"%06d\n",arr[n-1]);//坑点
    }
    return 0;
}