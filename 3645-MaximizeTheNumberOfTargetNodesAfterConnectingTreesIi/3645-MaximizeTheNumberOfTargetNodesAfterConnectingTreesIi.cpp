// Last updated: 06/07/2026, 18:51:42
class Solution {
private:
    int evenA = 0, oddA = 0, evenB = 0, oddB = 0;
public:
    vector<vector<int>> buildList(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    void bfs(vector<vector<int>>& adj, vector<int>& color, bool isA){
        queue<int> q;
        q.push(0);
        color[0] = 0;

        while (!q.empty()){
            int u = q.front(); q.pop();
            if (color[u] == 0){
                if (isA) evenA++;
                else evenB++;
            }
            else{
                if (isA) oddA++;
                else oddB++;
            }

            for (int v : adj[u]){
                if (color[v] == -1){
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> adjA = buildList(edges1);
        vector<vector<int>> adjB = buildList(edges2);

        const int n = adjA.size(), m = adjB.size();
        vector<int> colorA(n, -1), colorB(m, -1);
        evenA = 0; oddA = 0; evenB = 0; oddB = 0;

        bfs(adjA, colorA, true);
        bfs(adjB, colorB, false);

        int maxi = max(evenB, oddB);
        vector<int> result(n);
        for (int i = 0; i < n; ++i)
            result[i] = ((colorA[i] == 0) ? evenA : oddA) + maxi;
        return result;
    }
};