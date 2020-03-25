//字符串转整数

class Solution {
public:
    int strToInt(string str) {
        if(str.size()<=0)
            return 0;
        int i=0;
        while(str[i]==' ')
            i++;
        int flag=1;
        if(str[i]=='-')
        {
            flag=-1;
            i++;
        }           
        else if(str[i]=='+')
            i++;
        long long num=0;
        while(i<str.size())
        {
            if(str[i]<='9'&&str[i]>='0')
            {
                num=num*10+str[i]-'0';
                ++i;
            }
            else
            {
                break;
            }
            if(flag*num<INT_MIN)
            {
                return INT_MIN;
            }
            else if(flag*num>INT_MAX)
            {
                return INT_MAX;
            }
        }
        return (int)flag*num;
    }
};