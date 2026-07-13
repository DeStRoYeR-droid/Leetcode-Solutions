// Last updated: 13/07/2026, 22:17:02
class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;

        for (const int& price : prices){
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }
};