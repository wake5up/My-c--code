//万万没想到之抓捕孔连顺

#include <iostream>
#include <vector>
using namespace std;

long long Count(long long n)// Cn^2排列组合
{
    return n*(n-1)/2;
}

int main()
{
    long long n,d;
    while(cin>>n>>d)
    {
        vector<long long> v(n);
        long long sum=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            while(i>=2&&v[i]-v[j]>d)
            {
                j++;
            }
            sum=(sum+Count(i-j))%99997867;
        }
        cout<<sum<<endl;
    }
    return 0;
}