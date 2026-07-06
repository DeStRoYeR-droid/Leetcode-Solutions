// Last updated: 06/07/2026, 18:59:30
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);

        while (!q.empty()){
            int node = q.front(); q.pop();
            
            if (node == destination) return true;
            if (visited[node]) continue;

            visited[node] = true;
            for (const auto& neigh : adj[node]){
                if (visited[neigh]) continue;
                q.push(neigh);
            }
        }
        return false;
    }
};