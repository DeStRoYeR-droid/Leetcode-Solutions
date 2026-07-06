// Last updated: 06/07/2026, 18:51:58
static const vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()){
            auto [time, x, y] = pq.top(); pq.pop();
            if (x == m - 1 && y == n - 1) return time;

            for (const auto& dir : dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int waitTime = max(0, moveTime[nx][ny] - time);
                    int arriveTime = time + 1 + waitTime;

                    if (arriveTime < dist[nx][ny]){
                        dist[nx][ny] = arriveTime;
                        pq.push({arriveTime, nx, ny});
                    }
                }
            } 
        }   

        return -1;
    }
};