
//最长不含重复字符的子字符串
#include <iostream>
#include <string>
using namespace std;

int longestSubstring(const std::string& str)
{
    if(str.size()<=0)
        return 0;
    int curLength=0;
    int maxLength=0;
    int* arr=new int[26];
    for(int i=0;i<26;i++)
    {
        arr[i]=-1;
    }
    for(int i=0;i<str.size();i++)
    {
        int num=arr[str[i]-'a'];
        if(num<0||i-num>curLength)
        {
            curLength++;
        }
        else
        {
            if(curLength>maxLength)
                maxLength=curLength;

            curLength=i-num;
        }
        arr[str[i]-'a']=i;
    }
    if(curLength>maxLength)
        maxLength=curLength;
    delete[] arr;
    return maxLength;
}

int main()
{
    string s="arabcacfredk";
    int ret=longestSubstring(s);

    cout<<ret<<endl;
    return 0;
}
