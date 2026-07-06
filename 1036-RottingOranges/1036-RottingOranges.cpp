// Last updated: 06/07/2026, 19:06:30
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<int>> visited = grid;

        queue<pair<int, int>> q;
        int freshCount = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (visited[i][j] == 2) q.push({i, j});
                if (visited[i][j] == 1) freshCount++;
            }
        }

        if (freshCount == 0) return 0;
        if (q.empty()) return -1;

        int minutes = -1;
        static const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()){
            int size = q.size();
            while (size--){
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : dirs){
                    int i = x + dx;
                    int j = y + dy;

                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1){
                        visited[i][j] = 2;
                        freshCount--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }

        if (freshCount == 0) return minutes;
        return -1;
    }
};