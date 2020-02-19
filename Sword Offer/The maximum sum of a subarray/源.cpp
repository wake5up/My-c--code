//连续子数组的最大和

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max=0x80000000;
        int sum=0;
        for(int i=0;i<array.size();++i)
        {
            if(sum<=0)
                sum=array[i];
            else
                sum+=array[i];
            if(sum>max)
                max=sum;
        }
        return max;
    }
};