// Last updated: 06/07/2026, 18:56:11
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<int> vis(n + 1, false);
        queue<int> q;
        int result = INT_MAX;
        
        vis[1] = true;
        q.push(1);
        
        while (!q.empty()){
            int node = q.front(); q.pop();
            vis[node] = true;

            for (const auto& [next, distTo]: adj[node]){
                result = min(result, distTo);

                if (!vis[next]){
                    q.push(next);
                    vis[next] = true;
                }
            }
        }

        return result;
    }
};