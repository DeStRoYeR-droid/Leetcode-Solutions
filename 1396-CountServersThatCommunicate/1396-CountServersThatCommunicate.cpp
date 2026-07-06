// Last updated: 06/07/2026, 19:04:36
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        vector<int> row_count(rows, 0);
        vector<int> col_count(cols, 0);

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j){
                if (grid[i][j]){
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        int result = 0;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] && (row_count[i] > 1 || col_count[j] > 1)) result++;
            }
        }
        return result;
    }
};