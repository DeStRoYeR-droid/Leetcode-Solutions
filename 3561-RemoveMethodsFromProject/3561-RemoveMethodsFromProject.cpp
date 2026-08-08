// Last updated: 08/08/2026, 11:14:33
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& e : invocations){
            adj[e[0]].push_back(e[1]);
        }


        vector<bool> infect(n, false), vis(n, false);
        queue<int> q;
        q.push(k);

        infect[k] = true;

        while (!q.empty()){
            int ele = q.front(); q.pop();
            for (const int next : adj[ele]){
                if (!infect[next]){
                    q.push(next);
                    infect[next] = true;
                }
            }
        }

        bool cantRemove = false;
        for (const auto& e : invocations) {
            int u = e[0];
            int v = e[1];
            
            if (!infect[u] && infect[v]) {
                cantRemove = true;
                break;
            }
        }

        vector<int> result;
        if (cantRemove) {
            for (int i = 0; i < n; ++i){
                result.push_back(i);
            }
        } else {
            for (int i = 0; i < n; ++i){
                if (!infect[i]) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};