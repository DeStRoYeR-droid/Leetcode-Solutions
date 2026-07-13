// Last updated: 13/07/2026, 22:21:39
class Solution {
private:
    int countLiveNeighbors(int row, int col, const vector<vector<int>>& board, const int& rows, const int& cols){
        int result = 0;
        for (int i = -1; i <= 1; ++i){
            for (int j = -1; j <= 1; ++j){
                if (i == 0 && j == 0) continue;

                int nr = row + i, nc = col + j;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) result += (abs(board[nr][nc]) == 1);
            }
        }
        return result;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;

        const int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                int neighbors = countLiveNeighbors(i, j, board, rows, cols);

                if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = -1;
                else if (board[i][j] == 0 && neighbors == 3) board[i][j] = 2;
            }
        }

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                board[i][j] = (board[i][j] > 0) ? 1 : 0;
            }
        }
    }
};