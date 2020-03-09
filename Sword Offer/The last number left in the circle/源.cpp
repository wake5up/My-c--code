//圆圈中最后剩下的数

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0||m==0)
            return -1;
        list<int> li;
        for(int i=0;i<n;i++)
        {
            li.push_back(i);
        }
        int count=1;
        auto i=li.begin();
        while(li.size()>1)
        {
            if(i==li.end())
            {
                i=li.begin();
            }
            if(count==m)
            {
                i=li.erase(i);
                count=1;
            }
            else
            {
                count++;
                i++;
            }
        }
        return li.front();
    }
};