// Last updated: 12/11/2026, 22:49:24
class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        vector<vector<string>> result;
        int i = 0;
        while (i < n){
            if (s1[i] == s2[i]) ++i;
            else {
                string a, b;
                while (i < n && s1[i] != s2[i]){
                    a += s1[i];
                    b += s2[i];
                    ++i;
                }
                result.push_back({a, b});
            }
        }

        return result;
    }
};