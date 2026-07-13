// Last updated: 13/07/2026, 22:19:15
class Solution {
public:
    bool inBounds(int r, int c, int rows, int cols){
        if (0 <= r && r <rows && 0 <= c && c < cols) return true;
        return false;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {-1, 1, 0, 0};

        for (int i= 0; i < grid.size(); ++i){
            for (int j= 0; j < grid[0].size(); ++j){
                if (grid[i][j] == 1){
                    for (int k = 0; k < 4; ++k){
                        if (not(inBounds(i + dirX[k], j + dirY[k], grid.size(), grid[0].size()))) ++result;
                        else if (grid[i + dirX[k]][j + dirY[k]] == 0) ++result;
                    }
                }
            }
        }
        return result;
    }
};