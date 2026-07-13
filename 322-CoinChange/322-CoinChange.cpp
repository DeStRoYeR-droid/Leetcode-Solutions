// Last updated: 13/07/2026, 22:21:16
class Solution {
public:
    static int coinChange(vector<int>& coins, const int amount) {
        vector<int> minCoins(amount + 1, amount + 1);
        minCoins[0] = 0;
        for (int i = 0; i <= amount; ++i){
            for (int j = 0; j < coins.size(); ++j){
                if (i - coins[j] >= 0) 
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
            }
        }
        return minCoins[amount] != amount + 1 ? minCoins[amount] : -1;
    }
};