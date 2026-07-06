// Last updated: 06/07/2026, 19:04:03
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int result_city = -1, maxNum = INT_MAX;

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges){
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }

        for (int i = 0; i < n; ++i){
            int visited = numCities(n, i, adj, distanceThreshold);
            cout << "Visited " << visited << " cities via node " << i << endl;
            if (visited <= maxNum){
                maxNum = visited;
                result_city = i;
            }
        }
        return result_city;
    }

    int numCities(int n, int start, const vector<vector<pair<int, int>>>& adj, const int& threshold){
        vector<int> visited(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> pq;
        pq.push({0, start});
        int result = 0;

        while (!pq.empty()){
            auto [dist, node] = pq.top(); pq.pop();
            visited[node] = min(visited[node], dist);

            for (const auto& [d, next] : adj[node]){
                if (visited[next] != INT_MAX) continue;
                pq.push({dist + d, next});
            }
        }
        for (int i = 0; i < n; ++i){
            if (visited[i] <= threshold) ++result;
        }
        return result;
    }
};