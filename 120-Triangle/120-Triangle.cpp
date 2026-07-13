// Last updated: 13/07/2026, 22:26:41
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int n = triangle.size();
        const int m = triangle[n-1].size();

        vector<int> dp(m);
        for (int i = 0; i < m; i++) dp[i] = triangle[n-1][i];
        for (int i = n-2; i >= 0; i--){
            
            for (int j = 0; j <= i; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};