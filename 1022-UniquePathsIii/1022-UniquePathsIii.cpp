// Last updated: 24/08/2026, 22:47:11
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int start_x = 0, start_y = 0;
        int empty_count = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    empty_count++;
                } else if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        return dfs(grid, start_x, start_y, empty_count);
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y, int empty_count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
            return 0;
        }

        if (grid[x][y] == 2) {
            return empty_count == 0 ? 1 : 0;
        }

        grid[x][y] = -1;
        
        int result = dfs(grid, x + 1, y, empty_count - 1) +
                     dfs(grid, x - 1, y, empty_count - 1) +
                     dfs(grid, x, y + 1, empty_count - 1) +
                     dfs(grid, x, y - 1, empty_count - 1);

        grid[x][y] = 0;

        return result;
    }
};