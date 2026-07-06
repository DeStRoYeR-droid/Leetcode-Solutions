// Last updated: 06/07/2026, 19:08:20
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<vector<int>> result;
        queue<pair<int, vector<int>>> q;
        vector<int> cur;
        q.push({0, cur});

        vector<bool> visited(n, false);
        
        while (!q.empty()){
            auto top = q.front(); q.pop();
            int node = top.first;
            vector<int> path = top.second;

            if (visited[node]) continue;
            path.push_back(node);
            if (node == n - 1){
                result.push_back(path);
                continue;
            }

            for (int& neigh : graph[node]){
                if (visited[neigh]) continue;
                q.push({neigh, path});
            }
        }
        return result;
    }
};