// Last updated: 13/07/2026, 22:21:25
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        const int m = n + 2;

        vector<int>arr(m);
        arr[0] = 1;
        arr[n+1] = 1;
        for(int i = 0; i < n; i++) arr[i+1] = nums[i];

        vector<vector<int>>dp(m, vector<int>(m, 0));

        for(int len = 2; len <= m; len++) {
            for(int i = 0; i <= m - len; i++) {
                int j = i + len - 1;

                for(int k = i + 1; k < j; k++) {
                    int temp = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                    dp[i][j] = max(temp, dp[i][j]); 
                }
            }
        }

        return dp[0][n+1];
    }
};