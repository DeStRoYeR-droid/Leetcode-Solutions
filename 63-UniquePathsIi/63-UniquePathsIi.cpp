// Last updated: 13/07/2026, 22:28:45
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int n = obstacleGrid.size();
        const int m = obstacleGrid[0].size();

        if (obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = n -1; i >= 0; i--){
            if (obstacleGrid[i][m-1] == 0)
                dp[i][m-1] = 1;
            else break;
        }
        for (int i = m-1; i >= 0; i--){
            if (obstacleGrid[n-1][i] == 0)
                dp[n-1][i] = 1;
            else break;
        }

        for (int i = n-2; i >= 0; i--){
            for (int j = m-2; j >= 0; j--){
                if (obstacleGrid[i][j] == 1) continue;
                long long cur = (obstacleGrid[i][j+1] == 1) ? 0 : dp[i][j+1];
                cur += (obstacleGrid[i+1][j] == 1) ? 0 : dp[i+1][j];
                dp[i][j] = cur;
            }
        }

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; ++j){
        //         cout << dp[i][j] << " \t\t";
        //     }
        //     cout << endl;
        // }
        return dp[0][0];
    }
};