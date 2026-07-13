// Last updated: 13/07/2026, 22:26:23
class Solution {
private:
    int rows, cols;
    static int dirs[4][2];
    bool outOfBounds(const int& row, const int& col){
        return (row < 0 || col < 0 || row >= rows || col >= cols);
    }

    void dfs(const int row, const int col, vector<vector<char>>& grid){
        if (outOfBounds(row, col)) return;
        if (grid[row][col] != 'O') return;
        grid[row][col] = '1';
        for (const auto& dir : dirs){
            dfs(row + dir[0], col + dir[1], grid);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        this->rows = board.size();
        this->cols = board[0].size();

        for (int i = 0; i < rows; ++i){
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
        }

        for (int j = 0; j < cols; ++j){
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[rows - 1][j] == 'O') dfs(rows - 1, j, board);
        }

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (board[i][j] == '1') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
int Solution::dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};