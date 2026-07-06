// Last updated: 06/07/2026, 18:50:03
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        vector<bool> vis(n, false);
        vector<int> dist(n, 1e9);

        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if (vis[node]) continue;

            vis[node] = true;
            for (auto [v, w] : adj[node]){
                if (dist[node] + w < dist[v]){
                    dist[v] = dist[node] + w;
                    pq.push({-dist[v], v});
                }
            }
        }
        return (dist[n - 1] == 1e9) ? -1 : dist[n - 1];
    }
};