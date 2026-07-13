// Last updated: 13/07/2026, 22:21:45
class Solution {
public:
    int numSquares(const int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i <= n; ++i){
            for (int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }

        return dp[n];
    }
};