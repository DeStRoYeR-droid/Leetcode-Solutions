// Last updated: 13/07/2026, 22:29:05
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        empty_board(board);
        solve_board(board, n, result);
        return result;
    }

    void empty_board(vector<string>& board){
        const int n = board.size();
        string row;
        for (int width = 0; width < n; ++width) row += '.';
        for (int height = 0; height < n; ++height) board[height] = row;
    }

    void solve_board(vector<string>& board, int& n, vector<vector<string>>& possibilities, int iterations = 0){
        if (iterations >= n) { possibilities.emplace_back(board); return;}
        for (int row = 0; row < n; ++row){
            if (can_put(board, row, iterations)){
                board[row][iterations] = 'Q';
                solve_board(board, n, possibilities, iterations + 1);
                board[row][iterations] = '.';
            }
        }
    }

    bool can_put(vector<string>& board, int row, int column)
    {
        int rows=board.size(), columns=board[0].size();
        for(int temp_row=row, temp_column=column; temp_row>=0 and temp_column>=0; temp_row--, temp_column--)
            if(board[temp_row][temp_column]=='Q') return false;
        for(int temp_column=column; temp_column>=0; temp_column--)
            if(board[row][temp_column]=='Q') return false;
        for(int temp_row=row, temp_column=column; temp_row<rows and temp_column>=0; temp_row++, temp_column--)
            if(board[temp_row][temp_column]=='Q') return false;
        return true;
    }
};