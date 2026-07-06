// Last updated: 06/07/2026, 18:55:10
class Solution {
private:
    void dfs(int n, const vector<vector<int>>& graph, vector<int>& components, vector<bool>& visited){
        if (visited[n]) return;
        components.push_back(n);
        visited[n] = true;
        for (const auto neighbor : graph[n]){
            if (!visited[neighbor]){
                dfs(neighbor, graph, components, visited);
            }
        }
    }
public:
    int countCompleteComponents(const int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        vector<int> components;

        for (const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i){
            if (!visited[i]){
                dfs(i, graph, components, visited);
                int aux = components.size() - 1;
                bool done = true;

                for (const auto& c : components){
                    if (graph[c].size() != aux){
                        done = false;
                        break;
                    }
                }
                
                result += done;
                components.erase(components.begin(), components.end());
            }
        }
        return result;
    }
};