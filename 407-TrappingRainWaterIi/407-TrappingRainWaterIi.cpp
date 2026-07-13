// Last updated: 13/07/2026, 22:20:02
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        const int rows = heightMap.size();
        const int cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        for (int i = 0; i < rows; i++){
            for (int j : {0, cols-1}){
                minHeap.emplace(heightMap[i][j], i, j);
                visited[i][j] = true;
            }
        }

        for (int j = 0; j < cols; j++){
            for (int i : {0, rows-1}){
                if (!visited[i][j]){
                    minHeap.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int result = 0;

        while (!minHeap.empty()){
            auto [height, x, y] = minHeap.top();
            minHeap.pop();

            for (auto& dir : directions){
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny]){
                    result += max(0, height - heightMap[nx][ny]);
                    minHeap.emplace(max(height, heightMap[nx][ny]), nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
        return result;
    }
};