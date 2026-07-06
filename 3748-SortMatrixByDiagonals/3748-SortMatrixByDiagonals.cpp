// Last updated: 06/07/2026, 18:51:06
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        if (n == 1) return grid;
        vector<vector<int>> diags(2 * n - 1);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                diags[n + j - i - 1].push_back(grid[i][j]);
            }
        }

        int i = n - 1, j = 0;
        for (auto& row : diags){
            int c_i = i, c_j = j;

            if (i > 0 || j == 0) sort(row.rbegin(), row.rend());
            else sort(row.begin(), row.end());

            for (const auto& val : row){
                grid[c_i++][c_j++] = val;
            }
            
            if (i > 0) --i;
            else ++j;
        }

        return grid;
    }
};