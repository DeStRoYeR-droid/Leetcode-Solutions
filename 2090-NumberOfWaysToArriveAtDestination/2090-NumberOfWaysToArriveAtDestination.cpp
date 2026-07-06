// Last updated: 06/07/2026, 18:59:43
#define ull unsigned long long
#define int2 pair<ull, int>

const int mod = 1e9 + 7;
vector<int2> adj[200];

class Solution {
public:
    ull dijkstra(int start, int n, vector<ull> dist){
        vector<ull> way(n, 0);

        priority_queue<int2, vector<int2>, greater<>> pq;
        pq.emplace(0, start);
        way[start] = 1;

        while (!pq.empty()){
            auto [d0, i] = pq.top(); pq.pop();
            for (auto [d2, j] : adj[i]){
                ull newD = d0 + d2;
                if (newD < dist[j]){
                    dist[j] = newD;
                    way[j] = way[i];
                    pq.emplace(newD, j);
                }
                else if (newD == dist[j]){
                    way[j] += way[i];
                    way[j] %= mod;
                }
            }
        }
        return way[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        for (int i = 0; i < n; ++i) adj[i].clear();
        
        for (auto& e : roads){
            int u = e[0], v = e[1];
            ull time = e[2];

            adj[u].emplace_back(time, v);
            adj[v].emplace_back(time, u);
        }

        vector<ull> dist(n, ULLONG_MAX);
        dist[0] = 0;
        return dijkstra(0, n, dist);
    }
};