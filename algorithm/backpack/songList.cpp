//小Q的歌单（刚满歌单的个数）

//方法一
#include <iostream>
using namespace std;

#define NUM 1000000007

int dp[201][1001]={0};
int arr[201];
int main()
{
    int K;
    while(cin>>K)
    {
        int a,x,b,y;
        cin>>a>>x>>b>>y;
        for(int i=1;i<=x;i++)
            arr[i]=a;
        for(int i=x+1;i<=x+y;i++)
            arr[i]=b;
        dp[0][0]=1;
        for(int i=1;i<=x+y;i++)
        {
            for(int j=0;j<=K;j++)
            {
                if(j<arr[i])
                    dp[i][j]=dp[i-1][j]%NUM;
                else
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i]])%NUM;
            }
        }
        cout<<dp[x+y][K]<<endl;
    }
    return 0;
}
//方法二
#include <iostream>
using namespace std;

#define NUM 1000000007

int dp[1001]={0};
int arr[201];
int main()
{
    int K;
    while(cin>>K)
    {
        int a,x,b,y;
        cin>>a>>x>>b>>y;
        for(int i=1;i<=x;i++)
            arr[i]=a;
        for(int i=x+1;i<=x+y;i++)
            arr[i]=b;
        dp[0]=1;
        for(int i=1;i<=x+y;i++)
        {
            for(int j=K;j>=arr[i];j--)//逆序
            {
                dp[j]=(dp[j]+dp[j-arr[i]])%NUM;
            }
        }
        cout<<dp[K]<<endl;
    }
    return 0;
}