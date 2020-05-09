//最长上升子序列
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<int> temp(n,1);
        int maxNum=1;
        for(int i=1;i<n;i++)//以v[i]为结尾元素时
        {
            for(int j=0;j<i;j++)
            {
                if(v[j]<v[i])
                    temp[i]=max(temp[i],temp[j]+1);
            }
            maxNum=max(temp[i],maxNum);//判断哪个结尾元素所出现的升序子序列最长
        }
        cout<<maxNum<<endl;
    }
    return 0;
}