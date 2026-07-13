// Last updated: 13/07/2026, 22:18:29
class Solution {
public:
    void dfs(int cur, vector<vector<int>>& matrix, vector<int>& visited, int& label){
        if (visited[cur] != -1) return;

        visited[cur] = label; 
        
        for (int i = 0; i < matrix.size(); ++i){
            if (matrix[cur][i]){
                dfs(i, matrix, visited, label);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        vector<int> visited(n, -1);
        int label = 0;
        for (int i = 0; i < n; ++i){
            if (visited[i] == -1){
                dfs(i, isConnected, visited, label);
                label++;
            }
        }
        return label;
    }
};