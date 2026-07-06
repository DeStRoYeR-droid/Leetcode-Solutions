// Last updated: 06/07/2026, 19:08:28
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> minCost(n, INT_MAX);
        int stops = 0;

        while (!q.empty() && stops <= k){
            int s = q.size();
            while (s--){
                auto [node, cost] = q.front(); q.pop();
                for (auto& [neigh, price] : adj[node]){
                    if (price + cost < minCost[neigh]){
                        minCost[neigh] = price + cost;
                        q.push({neigh, minCost[neigh]});
                    }
                }
            }
            ++stops;
        }

        return (minCost[dst] == INT_MAX) ? -1 : minCost[dst];
    }
};