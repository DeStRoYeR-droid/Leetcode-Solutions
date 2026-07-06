// Last updated: 06/07/2026, 18:51:56
static const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        dist[0][0][0] = 0;
        pq.emplace(0, 0, 0, 0);

        while (!pq.empty()){
            auto [time, i, j, parity] = pq.top(); pq.pop();
            if (i == n - 1 && j == m - 1) return time;
            if (time > dist[i][j][parity]) continue;
            for (const auto[x, y] : dirs){
                int nx = i + x, ny = j + y;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int cost = (parity == 0) ? 1 : 2;
                    int waitTime = max(time, moveTime[nx][ny]);
                    int arrival = cost + waitTime;
                    int nextParity = 1 - parity;

                    if (arrival < dist[nx][ny][nextParity]){
                        dist[nx][ny][nextParity] = arrival;
                        pq.emplace(arrival, nx, ny, nextParity);
                    }
                }
            }
        }
        return -1;
    }
};