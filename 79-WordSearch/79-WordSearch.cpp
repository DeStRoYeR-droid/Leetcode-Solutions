// Last updated: 13/07/2026, 22:28:10
class Solution {
private:
    int rows, cols;
    static int dirs[4][2];
    bool outOfBounds(const int& row, const int& col){
        return (row < 0 || col < 0 || row >= rows || col >= cols);
    }

    bool dfs(const int& row, const int& col, vector<vector<char>>& grid, string& word, const int& index){
        if (word.size() == index) return true;

        if (outOfBounds(row, col)) return false;
        if (grid[row][col] != word[index]) return false;
        char temp = grid[row][col];
        grid[row][col] = '0';
        for (const auto& dir : dirs){
            if (dfs(row + dir[0], col + dir[1], grid, word, index + 1)) return true;
        }
        grid[row][col] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->rows = board.size();
        this->cols = board[0].size();
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (board[i][j] == word[0]){
                    if (dfs(i, j, board, word, 0)) return true;
                }                
            }
        }
        return false;
    }
};
int Solution::dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};