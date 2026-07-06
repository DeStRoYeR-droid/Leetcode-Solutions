// Last updated: 06/07/2026, 19:02:53
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        return dfs(adj, vector<bool>(n) = {}, 0);
    }

    int dfs(vector<vector<int>>& al, vector<bool>& visited, int from){
        int change = 0;
        visited[from] = true;
        for (const int to : al[from])
            if (!visited[abs(to)])
                change += dfs(al, visited, abs(to)) + (to > 0);
        return change;
    }
};