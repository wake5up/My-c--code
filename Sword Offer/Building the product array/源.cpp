//构建乘积数组

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len=a.size();
        if(len<=0)
            return {};
        vector<int> v(len);      
        vector<int> b1(len);
        vector<int> b2(len);
        b1[0]=a[0];
        b2[len-1]=a[len-1];
        for(int i=1;i<len;i++)
            b1[i]=b1[i-1]*a[i];
        for(int i=len-2;i>=0;i--)
            b2[i]=b2[i+1]*a[i];
        v[0]=b2[1];
        v[len-1]=b1[len-2];
        for(int i=1;i<len-1;i++)
            v[i]=b1[i-1]*b2[i+1];
        return v;
    }
};