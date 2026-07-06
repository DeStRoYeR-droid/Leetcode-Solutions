// Last updated: 06/07/2026, 18:52:25
class Solution {
public:
    inline bool inGrid(int x, int y, int r, int c){
        return (0 <= x && x < r) && (0 <= y && y < c);
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        deque<tuple<int, int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, -1));
        
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        q.push_front({0, 0, startHealth});
        vis[0][0] = startHealth; 
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        while (!q.empty()){
            auto [x, y, h] = q.front(); 
            q.pop_front();
            
            if (x == n - 1 && y == m - 1 && h > 0) return true;

            for (const auto [dx, dy] : dirs){
                int nx = x + dx;
                int ny = y + dy;

                if (inGrid(nx, ny, n, m)){
                    int nh = h - grid[nx][ny];
                    
                    if (nh > 0 && nh > vis[nx][ny]){
                        vis[nx][ny] = nh;
                        
                        if (grid[nx][ny] == 0){
                            q.push_front({nx, ny, nh});
                        } else {
                            q.push_back({nx, ny, nh});
                        }
                    }
                }
            }
        }
        return false;
    }
};