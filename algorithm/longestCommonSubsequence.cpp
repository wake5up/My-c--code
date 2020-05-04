//最长公共子序列个数

#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int getlength(const string &str1,const string &str2,vector<vector<int>> &dp)
{
    for(int i=1;i<=str1.size();i++)
    {
        for(int j=1;j<=str2.size();j++)
        {
            if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[str1.size()][str2.size()];
}
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
        int length=getlenght(str1,str2,dp);
        cout<<length<<endl;
    }
    return 0;
}

//最长公共子序列
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int getlength(const string &str1,const string &str2,vector<vector<int>> &dp)
{
    for(int i=1;i<=str1.size();i++)
    {
        for(int j=1;j<=str2.size();j++)
        {
            if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[str1.size()][str2.size()];
}
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
        int length=getlength(str1,str2,dp);
        string ans;
        ans.resize(length);
        int index = length-1,x=str1.size(),y=str2.size();
        while(index>=0)
        {
            if(y>=1&&dp[x][y]==dp[x][y-1])
                y--;
            else if(x>=1&&dp[x][y]==dp[x-1][y])
                x--;
            else
            {
                ans[index--]=str1[x];
                x--;
                y--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}