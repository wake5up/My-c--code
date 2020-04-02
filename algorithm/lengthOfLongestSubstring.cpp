//最长不含重复字符的子字符串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int count=0;
        int max=0;
        int* arr=new int[256];
        for(int i=0;i<256;i++)
        {
            arr[i]=-1;
        }
        for(int i=0;i<s.size();i++)
        {
            int index=arr[s[i]];
            if(index<0)
                count++;
            else if(index>=0&&i-index>count)
                count++;
            else
            {
                if(count>max)
                    max=count;
                count=i-index;
            }
            arr[s[i]]=i;
        }
        if(count>max)
            max=count;
        delete[] arr;
        return max;
    }
};