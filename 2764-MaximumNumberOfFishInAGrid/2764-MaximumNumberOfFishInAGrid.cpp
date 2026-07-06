// Last updated: 06/07/2026, 18:55:14
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        int result = 0;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j]) result = max(result, dfs(grid, i, j, rows, cols));
            }
        }
        return result;
    }
    int dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols){
        int fish = 0;
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) return fish;

        fish += grid[i][j];
        grid[i][j] = 0;
        fish += (dfs(grid, i, j+1, rows, cols)); 
        fish += (dfs(grid, i, j-1, rows, cols)); 
        fish += (dfs(grid, i+1, j, rows, cols)); 
        fish += (dfs(grid, i-1, j, rows, cols)); 

        return fish;
    }
};