// Last updated: 06/07/2026, 18:58:52
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        const int n = bombs.size(); 
        vector<vector<int>> adj(n);

        for (int i = 0; i < bombs.size(); ++i){
            long long sx = bombs[i][0];
            long long sy = bombs[i][1];
            long long sr = bombs[i][2];

            for (int j = 0; j < bombs.size(); ++j){
                int count = 0;
                if (i == j) continue;

                long long dx = sx - bombs[j][0];
                long long dy = sy - bombs[j][1];

                long long dist = (dx * dx + dy * dy);

                if (dist <= (long long)sr * sr) adj[i].push_back(j);
            }
        }

        int maxDetonated = 0;
        for (int i = 0; i < n; ++i){
            vector<bool> visited(n, false);
            maxDetonated = max(maxDetonated, dfs(i, adj, visited));
        }
        return maxDetonated;
    }

    int dfs(int parent, const vector<vector<int>>& adj, vector<bool>& visited){
        visited[parent] = true;
        int count = 1;
        for (int neighbor : adj[parent]){
            if (!visited[neighbor]){
                count += dfs(neighbor, adj, visited);
            }
        }
        return count;
    }
};