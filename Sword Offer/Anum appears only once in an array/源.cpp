//数组中唯一只出现一次的数字，其他数字都出现三次
#include <iostream>
#include <vector>
using namespace std;

bool flag=true;
int FindNumberApearingOnce(vector<int> data)
{
    int len=data.size();
    if(len<=0)
    {
        flag=false;
        return 0;
    }
    vector<int> v(32,0);
    for(int i=0;i<len;i++)
    {
        int bit=1;
        for(int j=31;j>=0;j--)
        {
            int a=data[i]&bit;
            if(a!=0)
                v[j]+=1;

            bit<<=1;
        }
    }
    int result=0;
    for(int i=0;i<32;i++)
    {
        result<<=1;
        result+=v[i]%3;
    }
    return result;
}

int main()
{
    vector<int> v={1,1,1,2,2,2,3,3,3,89,5,5,5};
    int ret=FindNumberApearingOnce(v);
    cout<<ret<<endl;
    return 0;
}
