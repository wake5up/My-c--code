//数组中只出现一次的数字

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len=data.size();
        int num=data[0];
        for(int i=1;i<len;i++)
        {
            num^=data[i];
        }
        int index=FindIndex(num);
        *num1=0;
        *num2=0;
        for(int i=0;i<len;i++)
        {
            if(Fun(data[i],index))
                *num1^=data[i];
            else
                *num2^=data[i];
        }
    }
    int FindIndex(int num)
    {
        int index=0;
        while(index<8*sizeof(int))
        {
            if((num&1)==1)
            {
                break;
            }
            num>>=1;
            ++index;
        }
        return index;
    }
    bool Fun(int a,int index)
    {
        a>>=index;
        return a&1;
    }
};