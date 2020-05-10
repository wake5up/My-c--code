//求和     输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来

#include <iostream>
#include <vector>
using namespace std;

void DFS(int n,int m,vector<int>& v,int start)
{
    if(m<0)
        return;
    if(m==0)
    {
        for(int i=0;i<v.size();i++)
            i==0?cout<<v[i]:cout<<" "<<v[i];
        cout<<endl;
    }
    for(int i=start;i<=n&&i<=m;i++)
    {
        v.push_back(i);
        DFS(n,m-i,v,i+1);
        v.pop_back();
    }
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> v;
        DFS(n,m,v,1);
    }
    return 0;
}