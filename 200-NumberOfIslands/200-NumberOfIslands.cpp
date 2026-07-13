// Last updated: 13/07/2026, 22:24:02
class Solution {
private:
    int rows, cols;
    static int dirs[4][2];
    bool outOfBounds(const int& row, const int& col){
        return (row < 0 || col < 0 || row >= rows || col >= cols);
    }

    void dfs(const int& row, const int& col, vector<vector<char>>& grid){
        if (outOfBounds(row, col)) return;
        if (grid[row][col] == '0') return;

        grid[row][col] = '0';
        for (const auto& dir : dirs){
            dfs(row + dir[0], col + dir[1], grid);
        }
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();

        int result = 0;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ++result;
                }
            }
        }
        return result;
    }
};
int Solution::dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};