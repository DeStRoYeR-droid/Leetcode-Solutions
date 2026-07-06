// Last updated: 06/07/2026, 19:08:30
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i){
            if (color[i] == -1){
                if (!bfs(i, graph, color)) return false;
            }
        }
        return true;
    }

    bool bfs(int start, const vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()){
            int node = q.front(); q.pop();

            for (const int& val : graph[node]){
                if (color[val] == -1){
                    color[val] = 1 - color[node];
                    q.push(val);
                }
                else if (color[val] == color[node]) return false;
            }
        }
        return true;
    }
};