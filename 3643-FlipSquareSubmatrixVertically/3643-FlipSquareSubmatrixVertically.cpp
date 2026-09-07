// Last updated: 07/09/2026, 22:28:03
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = 0; i < k/2; i++) {
            for(int j = 0; j < k; j++) {
                swap(grid[x+i][y+j], grid[x+k-1-i][y+j]);
            }
        }
        return grid;
    }
};