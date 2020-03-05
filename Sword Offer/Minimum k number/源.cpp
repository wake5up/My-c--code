//最小k个数

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> v;
        if(input.size()<=0||k<=0||k>input.size())
            return v;
        int start=0;
        int end=input.size()-1;
        int index=Partition(input,start,end);
        while(index!=k-1)
        {
            if(index>k-1)
            {
                end=index-1;
                index=Partition(input,start,end);
            }
            else
            {
                start=index+1;
                index=Partition(input,start,end);
            }
        }
        v.assign(input.begin(),input.begin()+k);
        return v;
    }
    int Partition(vector<int>& input,int start,int end)
    {
        int sum=input[start];
        int index=start;
        for(int i=start+1;i<=end;++i)
        {
            if(input[i]<sum)
            {
                ++index;
                if(index!=i)
                    swap(input[index],input[i]);
            }
        }
        swap(input[start],input[index]);
        return index;
    }
};