// Last updated: 06/07/2026, 19:08:17
class Solution {
private:
    int n;
    vector<int> isSafe;

public:
    bool dfs(int i, const vector<vector<int>>& graph){
        if (isSafe[i] != -1) return isSafe[i];
        isSafe[i] = 0;
        for (int j : graph[i]){
            if (!dfs(j, graph)) return isSafe[i] = 0;
        }
        return isSafe[i] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        isSafe = vector<int>(n, -1);
        vector<int> result;

        for (int i = 0; i < n; ++i) 
            if (!graph[i].size()) isSafe[i] = 1;

        for (int i = 0; i < n; ++i)
            if (dfs(i, graph)) result.push_back(i);
        return result;
    }
};