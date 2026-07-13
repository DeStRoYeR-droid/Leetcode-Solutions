// Last updated: 13/07/2026, 22:26:35
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0], buy2 = -prices[0], sell1 = 0, sell2 = 0;
        for (int i = 1; i < prices.size(); ++i){
            int price = prices[i];

            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};