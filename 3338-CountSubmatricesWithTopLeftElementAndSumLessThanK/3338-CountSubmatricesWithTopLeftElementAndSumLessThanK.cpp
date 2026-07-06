// Last updated: 06/07/2026, 18:53:27
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), result = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (i > 0 && j == 0) grid[i][j] += grid[i - 1][j];
                else if (i == 0 && j > 0) grid[i][j] += grid[i][j - 1];
                else if (i > 0 && j > 0) grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];

                if (grid[i][j] <= k) ++result;
            }
        }
        return result;
    }
};