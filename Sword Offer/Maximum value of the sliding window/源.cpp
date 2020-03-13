//滑动窗口的最大值

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> v;
        int len=num.size();
        if(len<=0||size>len||size<1)
            return v;
        deque<int> d;
        for(unsigned int i=0;i<len;i++)
        {
            while(!d.empty()&&num[i]>num[d.back()])
                d.pop_back();
            while(!d.empty()&&i-d.front()>=size)
                d.pop_front();
            d.push_back(i);
            if(i>=size-1)
                v.push_back(num[d.front()]);
        }
        return v;
    }
};