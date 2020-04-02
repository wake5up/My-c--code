//数组中的逆序对

class Solution {
public:
    int count=0;
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        vector<int> v(nums.size());
        merge_sort(nums,v,0,nums.size()-1);
        return count;
    }
    void merge_sort(vector<int>& nums,vector<int>& v,int l,int r)
    {
        if(l>=r)
            return;
        int mid=(l+r)/2;
        merge_sort(nums,v,l,mid);
        merge_sort(nums,v,mid+1,r);
        int i=l;
        int j=mid+1;
        int k=l;
        while(i<=mid&&j<=r)
        {
            if(nums[i]>nums[j])
            {
                count+=(mid-i+1);
                v[k++]=nums[j++];
            }
            else
            {
                v[k++]=nums[i++];
            }
        }
        while(i<=mid)
            v[k++]=nums[i++];
        while(j<=r)
            v[k++]=nums[j++];
        for(int i=l;i<=r;i++)
            nums[i]=v[i];
    }
};