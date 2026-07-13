// Last updated: 13/07/2026, 22:21:10
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        vector<vector<int>> indegree(n, vector<int>(m, 0));
        static const vector<pair<int, int>> dirs = {{1,0}, {-1, 0}, {0, -1}, {0,1}};

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                for (const auto[x, y] : dirs){
                    int dx = i + x;
                    int dy = j + y;

                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && matrix[dx][dy] > matrix[i][j]){
                        ++indegree[dx][dy];
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (indegree[i][j] == 0) q.push({i, j});
            }
        }

        int result = 0;

        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [i, j] = q.front(); q.pop();

                for (auto [x, y] : dirs){
                    int nx = i + x;
                    int ny = j + y;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[i][j]){
                        indegree[nx][ny]--;
                        if (indegree[nx][ny] == 0){
                            q.push({nx, ny});
                        }
                    }
                }
            }

            ++result;
        }

        return result;
    }
};