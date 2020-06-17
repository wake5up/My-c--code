//机器人跳跃问题

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int N;
    int ans = 0;
    cin >> N;
    vector<int>D(N,0);
    for(int i = 0;i<N;i++)
        cin >>D[i];
    for(int j=N-1;j>=0;j--)
    {
        ans = ceil((D[j]+ans)/2.0);//注意c++中除法整数/整数为0，ceil向上取整要整数/float类型
    }
    cout<<ans<<endl;
    return 0;
}