// Last updated: 06/07/2026, 19:04:32
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));
        int result = 0;
        
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (matrix[i][j] == 1){
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1;
                    result += dp[i+1][j+1];
                }
            }
        }
        return result;
    }
};