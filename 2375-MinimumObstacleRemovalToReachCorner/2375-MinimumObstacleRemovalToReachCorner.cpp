// Last updated: 02/08/2026, 14:15:43
using pii = pair<int, int>;
vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
class Solution {
public:
    static bool isInside(int x, int y, int n, int m){
        return (0 <= x && x < n && 0 <= y && y < m);
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dist(n * m, INT_MAX);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, 0);
        dist[0] = 0;

        while (!pq.empty()){
            auto [currD, index] = pq.top(); pq.pop();
            int x = index / m, y = index % m;

            if (x == n - 1 && y == m - 1) return currD;

            for (auto [dx, dy] : dirs){
                int nx = x + dx, ny = y + dy;
                if (isInside(nx, ny, n, m)){
                    int newD = currD + grid[nx][ny];
                    if (dist[nx * m + ny] > newD){
                        dist[nx * m + ny] = newD;
                        pq.emplace(newD, nx * m + ny);
                    }
                }
            }
        }

        // Algorithm should never actually reach here
        return -1;
    }
};