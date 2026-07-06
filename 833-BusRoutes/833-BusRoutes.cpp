// Last updated: 06/07/2026, 19:08:07
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> adj;
        for (int r = 0; r < routes.size(); r++) {
            for (int stop : routes[r]) {
                adj[stop].push_back(r);
            }
        }
        queue<int> que; 
        vector<int> visited(501, false); 
        for (auto i : adj[source]) {
            que.push(i);
            visited[i] = true;
        }

        int c = 1; 

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int i = que.front();
                que.pop();

                for (auto stop : routes[i]) {
                    if (stop == target) {
                        return c;
                    }
                    for (auto it : adj[stop]) {
                        if (!visited[it]) {
                            visited[it] = true; 
                            que.push(it);
                        }
                    }
                }
            }
            c++;
        }
        return -1;
    }
};