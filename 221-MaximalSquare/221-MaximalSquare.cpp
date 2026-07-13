// Last updated: 13/07/2026, 22:23:03
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));
        int maxLength = 0;
        
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (matrix[i][j] == '1'){
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1;
                    maxLength = max(maxLength, dp[i+1][j+1]);
                }
            }
        }

        return maxLength * maxLength;
    }
};