// Last updated: 06/07/2026, 18:51:51
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        const int n = edges1.size(), m = edges2.size();
        int maxi = 0;
        vector<vector<int>> adj1(n + 1), adj2(m + 1);
        for (auto& e : edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> result(n + 1);
        for (int i = 0; i < m + 1; ++i) maxi = max(maxi, dfs(adj2, i, -1, k - 1));
        for (int i = 0; i < n + 1; ++i) result[i] = dfs(adj1, i, -1, k) + maxi;
        return result;
    }

    int dfs(const vector<vector<int>>& adj, int u, int p, int k){
        if (k < 0) return 0;
        int count = 1;
        for (int v : adj[u]){
            if (v != p) count += dfs(adj, v, u, k -1);
        }
        return count;
    }
};