// Last updated: 02/08/2026, 14:24:32
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int dim = n * m;
        k = k % dim;

        if (k == 0) return grid;
        
        auto shift = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / m][i % m], grid[j / m][j % m]);
                i++;
                j--;
            }
        };

        shift(0, dim - 1);
        shift(0, k - 1);
        shift(k, dim - 1);
        return grid;
    }
};