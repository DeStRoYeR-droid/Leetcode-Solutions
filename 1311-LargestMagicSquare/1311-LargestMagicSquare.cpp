// Last updated: 06/07/2026, 19:05:05
class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& g, int i, int j, int k) {
        int sum = 0;

        for (int x = i; x < i + k; x++) {
            int s = 0;
            for (int y = j; y < j + k; y++) s += g[x][y];
            if (x == i) sum = s;
            else if (sum != s) return false;
        }

        for (int y = j; y < j + k; y++) {
            int s = 0;
            for (int x = i; x < i + k; x++) s += g[x][y];
            if (sum != s) return false;
        }

        int s = 0;
        for (int d = 0; d < k; d++) s += g[i + d][j + d];
        if (sum != s) return false;

        s = 0;
        for (int d = 0; d < k; d++) s += g[i + d][j + k - 1 - d];
        if (sum != s) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int maxSz = min(n, m);
        int result = 1;

        for (int sz = 2; sz <= maxSz; ++sz){
            for (int i = 0; i + sz <= n; ++i){
                for (int j = 0; j + sz <= m; ++j){
                    if (isMagicSquare(grid, i, j, sz)) result = sz;
                }
            }
        } 
        return result;
    }
};