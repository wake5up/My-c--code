//1~n整数中1出现的次数

class Solution {
public:
    int countDigitOne(int n) {
        if( n < 0)
        return 0;
        int i = 0;
        int high = n;
        int cnt = 0;
        while(high != 0)
        {
            high = n / pow(10 ,i+1);//high表示当前位的高位
            int temp = n / pow(10, i);
            int cur = temp % 10;//cur表示第i位上的值，从1开始计算
            int low = n  - temp * pow(10, i);//low表示当前位的低位
            if(cur < 1)
            {
                cnt += high * pow(10, i);
            }
            else if(cur > 1)
            {
                cnt += (high + 1) * pow(10 ,i);
            }
            else
            { 
                cnt += high * pow(10, i);
                cnt += (low + 1); 
            }
            i++;
        }
        return cnt;
    }
};