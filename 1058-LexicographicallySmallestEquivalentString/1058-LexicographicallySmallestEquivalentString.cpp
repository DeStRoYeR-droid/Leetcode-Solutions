// Last updated: 06/07/2026, 19:06:22
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        const int n = s1.size();
        unordered_map<char, vector<char>> adj;

        for (int i = 0; i < n; ++i){
            char u = s1[i], v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result = "";
        for (const char& ch : baseStr){
            vector<bool> vis(26, 0);
            char minChar = dfs(adj, ch, vis);
            result.push_back(minChar);
        }
        return result;
    }

    char dfs(unordered_map<char, vector<char>>& adj, char cur, vector<bool>& vis){
        vis[cur - 'a'] = true;
        char minChar = cur;
        for (char& neighbor : adj[cur]){
            if (!vis[neighbor - 'a']){
                minChar = min(minChar, dfs(adj, neighbor, vis));
            }
        }
        return minChar;
    }
};