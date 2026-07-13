// Last updated: 13/07/2026, 22:16:47
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>> pq;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times){
            adj[edge[0]].push_back({edge[2], edge[1]});
        }

        pq.push({0, k});
        int result = 0;
        vector<int> visited(n + 1, INT_MAX);
        visited[0] = 0;

        while (!pq.empty()){
            auto [time, node] = pq.top(); pq.pop();

            visited[node] = min(visited[node], time);

            for (const auto& neigh : adj[node]){
                if (visited[neigh.second] > time + neigh.first)
                    pq.push({time + neigh.first, neigh.second});
            }
        }

        for (const int& val : visited){
            if (val == INT_MAX) return -1;
            result = max(result, val);
        }
        return result;
    }
};