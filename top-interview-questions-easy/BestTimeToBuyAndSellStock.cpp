class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int profit = 0;
        int minPrice = prices[0];
        
        for(int i = 1; i<prices.size();++i)
        {
            if(prices[i] > minPrice)
            {
                profit = max(profit, (prices[i] - minPrice));  
            }else{
                minPrice = prices[i];
            }
        }
        return profit;
    }
};
