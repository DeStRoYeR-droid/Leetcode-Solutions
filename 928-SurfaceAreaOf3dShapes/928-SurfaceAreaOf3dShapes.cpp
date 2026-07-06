// Last updated: 06/07/2026, 19:07:22
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        const int n = grid.size();
        if (n == 1){
            return grid[0][0] * 4 + (grid[0][0] ? 2 : 0); 
        }
        int result = 0;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                // top and bottom will always count, no matter
                if (grid[i][j] != 0) result += 2;
                // edges as well
                if (i == 0 || i == n - 1) result += grid[i][j];
                // corners too :)
                if (j == 0 || j == n - 1) result += grid[i][j];

                if (i)
                    result += abs(grid[i][j] - grid[i-1][j]);
                if (j)
                    result += abs(grid[i][j] - grid[i][j-1]);

            }
        }

        return result;
    }
};