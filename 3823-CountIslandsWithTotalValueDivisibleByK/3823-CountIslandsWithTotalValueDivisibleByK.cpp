// Last updated: 06/07/2026, 18:50:32
static const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int result = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] != 0){
                    long long val = getValue(grid, i, j, n, m, k);
                    result += (val == 0);
                }
            }
        }
        return result;
    }

    inline bool inBounds(int r, int c, int n, int m){
        return (0 <= r && r < n) && (0 <= c && c < m);
    }

    long long getValue(vector<vector<int>>& grid, int i, int j, int n, int m, int k){
        int value = grid[i][j] % k;
        grid[i][j] = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()){
            auto [x, y] = q.front(); q.pop();
            value += grid[x][y];

            grid[x][y] = 0;
            for (const auto [dx, dy]: dirs){
                int nx = x + dx;
                int ny = y + dy;

                if (inBounds(nx, ny, n, m) && grid[nx][ny]){
                    value = (value + grid[nx][ny]) % k;
                    grid[nx][ny] = 0; 
                    q.push({nx, ny});
                }
            }
        }
        return value;
    }
};