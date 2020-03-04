//左旋转字符串

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.size();
        if(len<=0||n>len||n<0)
            return "";
        Reverse(str,0,n-1);
        Reverse(str,n,len-1);
        Reverse(str,0,len-1);
        return str;
    }
    void Reverse(string &str,int begin,int end)
    {
        while(begin<=end)
        {
            int temp=str[begin];
            str[begin]=str[end];
            str[end]=temp;
            begin++;
            end--;
        }
    }
};