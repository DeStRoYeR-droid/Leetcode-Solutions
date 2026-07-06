// Last updated: 06/07/2026, 19:07:27
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        vector<int> rowMax,colMax;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                result += (grid[i][j] != 0);
            }
            rowMax.push_back(*max_element(grid[i].begin(), grid[i].end()));
        }

        for (int j = 0; j < cols; ++j){
            int column = grid[0][j];
            for (int i = 1; i < rows; ++i) column = max(column, grid[i][j]);
            colMax.push_back(column);
        }
        return result + accumulate(rowMax.begin(), rowMax.end(), 0) + 
            accumulate(colMax.begin(), colMax.end(), 0); 
    }
};