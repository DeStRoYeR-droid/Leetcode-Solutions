// Last updated: 06/07/2026, 19:07:52
class Solution {
public:
    bool isMagic(const vector<vector<int>>& grid, int r, int c){
        vector<bool> vals(10, 0);
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9) return false;
                if (vals[num]) return false;
                vals[num] = true;
            }
        }

        int d1 = 0, d2 = 0, c1 = 0, c2 = 0, c3 = 0, r1 = 0, r2 = 0, r3 = 0;
        for (int i = 0; i < 3; ++i){
            // Diagonals
            d1 += grid[r + i][c + i];
            d2 += grid[r + 2 - i][c + i];
            
            // Columns
            c1 += grid[r + i][c];
            c2 += grid[r + i][c + 1];
            c3 += grid[r + i][c + 2];
        }

        // Rows
        r1 = accumulate(grid[r].begin() + c, grid[r].begin() + c + 3, 0);
        r2 = accumulate(grid[r + 1].begin() + c, grid[r + 1].begin() + c + 3, 0);
        r3 = accumulate(grid[r + 2].begin() + c, grid[r + 2].begin() + c + 3, 0);

        if (r1 == 15 && r2 == 15 && r3 == 15 && c1 == 15 && c2 == 15 && c3 == 15 && d1 == 15 && d2 == 15) return true;
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        int result = 0;
        for (int i = 0; i < n - 2; ++i){
            for (int j = 0; j < m - 2; ++j){
                if (isMagic(grid, i, j)){
                    ++result;
                }
            }
        }

        return result;
    }
};