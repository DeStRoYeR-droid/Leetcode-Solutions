// Last updated: 06/07/2026, 18:59:37
class Solution {
public:
    bool bfs(int row, int col, const vector<vector<int>>& cells, int m){
        vector<vector<int>> mat(row, vector<int>(col, 0));
        static vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
        for (int i = 0; i < m; ++i) mat[cells[i][0] - 1][cells[i][1] - 1] = 1;

        queue<pair<int, int>> q;
        for (int i = 0; i < col; ++i){
            if (mat[0][i] == 0){
                q.push({0, i});
                mat[0][i] = 1;
            }
        }

        while (!q.empty()){
            auto [x, y] = q.front(); q.pop();
            if (x == row -1) return true;
            for (auto& [dx, dy] : dirs){
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < row && 0 <= ny && ny < col
                    && mat[nx][ny] == 0){
                    mat[nx][ny] = 1;
                    if (nx == row - 1) return true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = cells.size();
        while (left < right){
            int mid = left + (right - left) / 2;
            if (bfs(row, col, cells, mid)){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return right - 1;
    }
};