// Last updated: 06/07/2026, 19:08:35
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        set<pair<int, int>> seen;

        pq.push({grid[0][0], 0 , 0});
        while (!pq.empty()){
            auto [max_d, r, c] = pq.top(); pq.pop();
            
            if (seen.count({r, c})) continue;
            seen.insert({r, c});

            if (r == n - 1 && c == m - 1) return max_d;

            for (auto [dr, dc] : dirs){
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !seen.count({nr, nc})){
                    int nextD = max(max_d, grid[nr][nc]);
                    pq.push({nextD, nr, nc});
                }
            }
        }
        return -1;
    }
};