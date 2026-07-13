// Last updated: 13/07/2026, 22:20:34
class Solution {
public:
    int combinationSum4(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int cur = 1; cur <= amount; cur++){
            for (const int& coin : coins){
                if (coin <= cur) dp[cur] += dp[cur - coin];
                else break;
            }
        }
        return dp[amount];
    }
};