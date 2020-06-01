//贪吃的小Q

#include <iostream>
using namespace std;

int Sum(int num,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=num;
        num=(num+1)/2;
    }
    return sum;
}

int Fun(int n,int m)
{
    int start=1;
    int end=m;
    while(start<=end)
    {
        int mid=(start+end+1)/2;
        int sum=Sum(mid,n);
        if(sum==m)
            return mid;
        else if(sum<m)
            start=mid+1;
        else
            end=mid-1;
    }
    return end;
}

int main()
{
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<m<<endl;
        return 0;
    }
    int ret=Fun(n,m);
    cout<<ret<<endl;
    return 0;
}