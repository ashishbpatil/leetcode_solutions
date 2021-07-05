class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = -1;
        for(int i=0; i < prices.size() - 1; ++i)
        {
            if(buy == -1)
            {
                if(prices[i] < prices[i + 1])
                {
                    buy = prices[i];
                }
            }
            else
            {
                if(prices[i] > prices[i+1])
                {
                    profit += prices[i] - buy;
                    buy = -1;
                }
            }
        }
        if(buy != -1)
        {
            if(buy < prices[prices.size() - 1])
                profit += prices[prices.size() - 1] - buy;
        }
        return profit;
    }
};
