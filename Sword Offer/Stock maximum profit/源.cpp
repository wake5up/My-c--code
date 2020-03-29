//股票最大利润

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int min=prices[0];
        int max=prices[1]-prices[0];
        for(int i=2;i<prices.size();i++)
        {
            if(prices[i-1]<min)
                min=prices[i-1];
            int temp=prices[i]-min;
            if(temp>max)
                max=temp;
        }
        if(max<0)
            return 0;
        return max;
    }
};