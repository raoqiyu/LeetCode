class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Dynamic Programming
        // i : 1-m
        // sell[i] : profit at the i-th day if the action at day i is sell or nothing
        // buy[i]  : profit at the i-th day if the action at day i is buy  or nothing
        // sell[i] = max(sell[i-1], buy[i-1]+prices[i])
        //                   if day i you do nothing, then sell[i] is same as sell[i-1]
        //                   if day i you sell the max preofit you can get is the your last buy is at day i-1, because buy[k] always >= buy[k-1]
        // buy[i]  = max(buy[i-1], sell[i-2]-prices[i]) 
        //          colldown if day i you buy then day i-1 you cannot sell, so profit is sell[i-1] - prces[i]
        //                   if day i you do nothing, then buy[i] is same as buy[i-1]
        int m = prices.size();
        if(m == 0)
            return 0;
        vector<int> buy(m+1, 0);
        vector<int> sell(m+1, 0);
        buy[1] = - prices[0];
        
        for(int i = 2; i <= m; i++){
            buy[i]  = max(buy[i-1],  sell[i-2]-prices[i-1]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i-1]);
        }
        
        return sell[m];
    }
};
