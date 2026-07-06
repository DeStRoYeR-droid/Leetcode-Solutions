// Last updated: 06/07/2026, 19:00:29
class Solution {
public:
    int dfs(int node, const string& colors, const vector<vector<int>>& adj, vector<vector<int>>& count, vector<int>& vis){
        if (!vis[node]){
            vis[node] = 1;
            for (int next : adj[node]){
                if (dfs(next, colors, adj, count, vis) == INT_MAX) return INT_MAX;
                for (int c = 0; c < 26; ++c){
                    count[node][c] = max(count[node][c], count[next][c]);
                }
            }
            ++count[node][colors[node] - 'a'];
            vis[node] = 2;
        }
        return vis[node] == 2 ? count[node][colors[node] - 'a'] : INT_MAX;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n), count(n, vector<int>(26, 0));
        vector<int> vis(n);

        for (auto edge : edges) adj[edge[0]].push_back(edge[1]);

        int result = 0;
        for (int i = 0; i < n && result != INT_MAX; ++i)
            result = max(result, dfs(i, colors, adj, count, vis));
        return result == INT_MAX ? -1 : result;
    }
};