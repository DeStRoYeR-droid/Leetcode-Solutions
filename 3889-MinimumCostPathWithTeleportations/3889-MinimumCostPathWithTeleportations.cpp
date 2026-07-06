// Last updated: 06/07/2026, 18:50:01
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int INF = 1e9;
        
        vector<vector<int>> dp(m, vector<int>(n, INF));
        dp[m - 1][n - 1] = 0;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                
                int cost = INF;
                if (i + 1 < m) cost = min(cost, grid[i + 1][j] + dp[i + 1][j]);
                if (j + 1 < n) cost = min(cost, grid[i][j + 1] + dp[i][j + 1]);
                
                dp[i][j] = cost;
            }
        }
        
        for (int step = 1; step <= k; step++) {
            vector<vector<int>> tmp = dp;
            vector<int> minV(10005, INF);
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    minV[grid[i][j]] = min(minV[grid[i][j]], dp[i][j]);
                }
            }
            
            for (int v = 1; v <= 10000; v++) {
                minV[v] = min(minV[v], minV[v - 1]);
            }

            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        tmp[i][j] = 0;
                        continue;
                    }
                    
                    int cost = tmp[i][j];
                    
                    if (i + 1 < m) cost = min(cost, grid[i + 1][j] + tmp[i + 1][j]);
                    if (j + 1 < n) cost = min(cost, grid[i][j + 1] + tmp[i][j + 1]);
                    
                    cost = min(cost, minV[grid[i][j]]);
                    
                    tmp[i][j] = cost;
                }
            }
            dp = tmp;
        }
        
        return dp[0][0];
    }
};