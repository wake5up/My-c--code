//把数组排成最小的数

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size()<=0)
            return "";
        sort(numbers.begin(),numbers.end(),cmp);
        string str;
        for(auto e:numbers)
            str+=to_string(e);
        return str;
    }
    static bool cmp(int a,int b)
    {
        string str1=to_string(a)+to_string(b);
        string str2=to_string(b)+to_string(a);
        return str1<str2;
    }
};