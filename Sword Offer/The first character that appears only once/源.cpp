//第一个只出现一次的字符

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(auto e:s)
            m[e]++;
        for(auto e:s)
        {
            if(m[e]==1)
                return e;
        }
        return ' ';
    }
};

//
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==1)
            {
                return s[i];
            }
        }
        return ' ';
    }
};