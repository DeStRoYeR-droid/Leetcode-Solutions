// Last updated: 06/07/2026, 18:54:40
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int result = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for (const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, values, visited, adj, k, result);
        return result;
    }

    long long dfs(int n, const vector<int>& values, vector<bool>& visited, const vector<vector<int>>& adj, const int& k, int& result){
        visited[n] = true;
        long long total = values[n];

        for (const int& neigh : adj[n]){
            if (!visited[neigh]){
                total += dfs(neigh, values, visited, adj, k, result);
            }
        }

        if (total % k == 0){
            result += 1;
            return 0;
        }
        return total;
    }
};