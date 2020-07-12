//01背包
//方法一
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int pack,n;//背包大小，物品个数
    while(cin>>pack>>n)
    {
        vector<int> size(n+1);//各个物品的大小
        vector<int> value(n+1);//各个物品的价值
        vector<vector<int>> arr(n+1,vector<int>(pack+1));
        for(int i=1;i<=n;i++)
        {
            cin>>size[i]>>value[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=pack;j++)
            {
                if(size[i]>j)
                    arr[i][j]=arr[i-1][j];
                else
                {
                    arr[i][j]=max(arr[i-1][j],arr[i-1][j-size[i]]+value[i]);
                }
            }
        }
        cout<<arr[n][pack]<<endl;
    }
    return 0;
}
//方法二
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int pack,n;
    while(cin>>pack>>n)
    {
        vector<int> size(n+1);
        vector<int> value(n+1);
        vector<int> arr(pack+1);
        for(int i=1;i<=n;i++)
        {
            cin>>size[i]>>value[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=pack;j>=size[i];j--)
            {
                arr[j]=max(arr[j],arr[j-size[i]]+value[i]);
            }
        }
        cout<<arr[pack]<<endl;
    }
    return 0;
}