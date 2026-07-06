// Last updated: 06/07/2026, 19:05:10
class Solution {
    int timer = 1;
    void dfs(int node, int parent, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<vector<int>>& bridges, vector<vector<int>>& adj){
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]){
            if (it == parent) continue;

            if (!vis[it]){
                dfs(it, node, tin, low, vis, bridges, adj);
                low[node] = min(low[node], low[it]);
                if (tin[node] < low[it])
                    bridges.push_back({it, node});
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), result;
        vector<int> vis(n, 0), tin(n), low(n);
        for (auto& conn : connections){
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1, tin, low, vis, result, adj);
        return result;
    }
};