// Last updated: 13/07/2026, 22:18:41
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = ((long long) dp[j] + (long long) dp[j - coin]) % INT_MAX;
            }
        }
        return dp[amount];
    }
};