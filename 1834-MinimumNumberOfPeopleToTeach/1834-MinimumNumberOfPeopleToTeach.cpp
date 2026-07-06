// Last updated: 06/07/2026, 19:01:16
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> need;
        for (const auto& p : friendships){
            int u = p[0] - 1, v = p[1] - 1;
            bool okay = false;
            for (const int& x : languages[u]){
                for (const int& y : languages[v]){
                    if (x == y){
                        okay = true;
                        break;
                    }
                }
            } 
            if (!okay){
                need.insert(u);
                need.insert(v);
            }  
        }

        int result = languages.size() + 1;
        for(int i = 1; i <= n; ++i) {
            int cans = 0;
            for(auto v : need) {
                bool found = false;
                for(auto c : languages[v]) {
                    if (c == i) { found = true; break; }
                }
                if (!found) ++cans;
            }
            result = min(result, cans);
        }
        return result;
    }
};