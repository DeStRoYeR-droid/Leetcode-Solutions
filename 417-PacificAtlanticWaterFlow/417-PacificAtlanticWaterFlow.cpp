// Last updated: 13/07/2026, 22:19:53
class Solution {
public:
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col, const int& lastVal, bool& pacific, bool& atlantic){
        if (row < 0 || col < 0){
            pacific = true;
            return;
        }
        if (row >= heights.size() || col >= heights[0].size()){
            atlantic = true;
            return;
        }
        if (pacific && atlantic) return;
        if (heights[row][col] > lastVal) return;
        if (visited[row][col]) return;

        visited[row][col] = true;
        dfs(heights, visited, row + 1, col, heights[row][col], pacific, atlantic);
        dfs(heights, visited, row - 1, col, heights[row][col], pacific, atlantic);
        dfs(heights, visited, row, col + 1, heights[row][col], pacific, atlantic);
        dfs(heights, visited, row, col - 1, heights[row][col], pacific, atlantic);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int n = heights.size(), m = heights[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                bool pacific = false, atlantic = false;
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                dfs(heights, visited, i, j, heights[i][j], pacific, atlantic);
                if (pacific && atlantic) result.push_back({i, j});
            }
        }
        return result;
    }
};