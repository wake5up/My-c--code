//把数字翻译成字符串

class Solution {
public:
    int translateNum(int num) {
        string str=to_string(num);
        unordered_set<string> se;
        for(int i=0;i<26;i++)
        {
            se.insert(to_string(i));
        }
        vector<int> dp(str.size()+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<dp.size();i++)
        {
            string s="";
            s+=str[i-2];
            s+=str[i-1];
            dp[i]+=dp[i-1];
            if(se.count(s))
                dp[i]+=dp[i-2];
        }
        return dp.back();
    }
};


class Solution {
public:
    int translateNum(int num) {
        string str=to_string(num);
        unordered_set<string> se;
        for(int i=0;i<26;i++)
        {
            se.insert(to_string(i));
        }
        int first1=1;
        int first2=1;
        int last;
        for(int i=2;i<=str.size();i++)
        {
            last=0;
            string s="";
            s+=str[i-2];
            s+=str[i-1];
            last+=first2;
            if(se.count(s))
                last+=first1;
            first1=first2;
            first2=last;
        }
        return first2;
    }
};