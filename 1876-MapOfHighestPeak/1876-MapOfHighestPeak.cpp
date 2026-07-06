// Last updated: 06/07/2026, 19:01:04
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int rows = isWater.size();
        const int cols = isWater[0].size();

        vector<vector<int>> result(rows, vector<int>(cols, rows + cols));
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (isWater[i][j]) result[i][j] = 0;
                else{
                    if (i > 0) result[i][j] = min(result[i][j], result[i-1][j] + 1);
                    if (j > 0) result[i][j] = min(result[i][j], result[i][j-1] + 1);
                }
            }
        }

        for (int i = rows - 1; i >= 0; --i){
            for (int j = cols - 1; j >= 0; --j){
                if (i < rows-1) result[i][j] = min(result[i][j], result[i+1][j] + 1);
                if (j < cols-1) result[i][j] = min(result[i][j], result[i][j+1] + 1);
            }
        }
        return result;
    }
};