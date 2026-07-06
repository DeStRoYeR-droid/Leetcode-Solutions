// Last updated: 06/07/2026, 18:49:18
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k + 1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                for (int cost = 0; cost <= k; ++cost){
                    if (dp[i][j][cost] == -1) continue;

                    int curr_score = dp[i][j][cost];

                    if (j + 1 < cols){
                        int val = grid[i][j + 1];
                        int addCost = (val != 0);
                        int addScore = val;
                        int newCost = cost + addCost;

                        if (newCost <= k){
                            dp[i][j + 1][newCost] = max(dp[i][j + 1][newCost], curr_score + addScore);
                        }
                    }

                    if (i + 1 < rows){
                        int val = grid[i + 1][j];
                        int addCost = (val != 0);
                        int addScore = val;
                        int newCost = cost + addCost;

                        if (newCost <= k){
                            dp[i + 1][j][newCost] = max(dp[i + 1][j][newCost], curr_score + addScore);
                        }
                    }
                }
            }
        }
        
        int result = -1;
        for (int cost = 0; cost <= k; ++cost){
            result = max(result, dp[rows - 1][cols - 1][cost]);
        }
        return result;
    }
};