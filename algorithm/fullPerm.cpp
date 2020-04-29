//字符串的全排列

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

vector<string> FullPerm(string s,int left,int right)
{
    if(left==right)
    {
        v.push_back(s);
        return v;
    }

    int temp=left;
    for(int i=left;i<=right;i++)
    {
        swap(s[temp],s[i]);
        FullPerm(s,left+1,right);
        swap(s[temp],s[i]);
    }
    return v;
}

int main()
{
    string s="12345";
    FullPerm(s,0,s.size()-1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
