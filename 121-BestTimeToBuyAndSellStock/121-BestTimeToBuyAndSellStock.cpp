// Last updated: 13/07/2026, 22:26:39
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int profit = 0;
        int maxSell = prices[n - 1];

        for (int i = n - 2; i >= 0; --i){
            profit = max(profit, maxSell - prices[i]);
            maxSell = max(prices[i], maxSell);
        }
        return profit;
    }
};