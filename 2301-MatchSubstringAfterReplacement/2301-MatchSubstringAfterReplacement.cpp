// Last updated: 07/09/2026, 22:47:15
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& m) {
        int n = s.size();
        int k = sub.size();

        vector<vector<bool>> mp(256, vector<bool>(256, false));
        
        for (int i = 0; i < m.size(); ++i){
            mp[m[i][0]][m[i][1]] = true;
        }

        for (int i = 0; i <= n - k; ++i){
            bool result = true;

            for (int j = 0; j < k; ++j){
                if (s[i + j] == sub[j]){
                    continue;
                }
                else if (mp[sub[j]][s[i + j]]){
                    continue;
                }
                else {
                    result = false;
                    break;
                }
            }

            if (result) return result;
        }
        return false;
    }
};