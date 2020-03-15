// 数字在排序数组中出现的次数

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()<=0)
            return 0;
        int i=Find(data,0,data.size()-1,k);
        if(i==-1)
            return 0;
        int j=i;
        for(;i<data.size();i++)
        {
            if(data[i]!=k)
                break;
        }
        for(;j>=0;j--)
        {
            if(data[j]!=k)
                break;
        }
        return i-j-1;
    }
    int Find(vector<int> v,int start,int end,int k)
    {
        int mid=0;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(v[mid]>k)
            {
                end=mid-1;
            }
            else if(v[mid]<k)
            {
                start=mid+1;
            }
            else
                return mid;
        }
        return -1;
    }
};