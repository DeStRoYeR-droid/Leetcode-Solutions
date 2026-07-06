// Last updated: 06/07/2026, 18:59:02
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        const int n = values.size();
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        return dfs(graph, values, maxTime, 0, 0, 0, visited);
    }

    int dfs(unordered_map<int, vector<pair<int, int>>>& graph,
            vector<int>& values, int maxTime, int startNode, int node,
            int currTime, vector<bool>& visited){
        
        if (currTime > maxTime) return INT_MIN;

        int result = INT_MIN, currVal = 0;

        if (node == startNode){
            result = visited[node] ? 0 : values[node];
        }

        for (auto neigh : graph[node]){
            currVal = visited[neigh.first] ? 0 : values[neigh.first];
            bool old = visited[neigh.first];
            visited[neigh.first] = true;

            result = max(result, 
                dfs(graph, values, maxTime, startNode, neigh.first, currTime +  neigh.second, visited) + currVal);

            visited[neigh.first] = old;
        }

        visited[node] = false;
        return result;
    }
};