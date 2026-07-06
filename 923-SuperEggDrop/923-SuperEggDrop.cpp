// Last updated: 06/07/2026, 19:07:25
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int j = 1; j <= k; j++) {
            dp[1][j] = 1;
        }
        for (int m = 1; m <= n; m++) {
            dp[m][1] = m;
        }
        for (int moves = 2; moves <= n; moves++) {
            for (int eggs = 2; eggs <= k; eggs++) {
                dp[moves][eggs] = 1 + dp[moves - 1][eggs - 1] + dp[moves - 1][eggs];
                if (dp[moves][eggs] >= n) {
                    return moves;
                }
            }
        }
        return n;
    }
};