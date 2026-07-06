// Last updated: 06/07/2026, 18:48:49
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= 3 && j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j] + costs[i - 1] + j * j);
            }
        }
        return dp[n];
    }
};