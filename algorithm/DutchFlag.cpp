//荷兰国旗

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DutchFlag(vector<int>& v)
{
    int left=0;
    int cur=0;
    int right=v.size()-1;
    while(cur<right)
    {
        if(v[cur]==0)
        { 
            swap(v[cur],v[left]);
            cur++;
            left++;
        }
        else if(v[cur]==2)
        {
            swap(v[cur],v[right]);
            right--;
        }
        else
            cur++;
    }
}

int main()
{
    vector<int> v={1,1,0,0,2,2,1,0,2};
    DutchFlag(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
