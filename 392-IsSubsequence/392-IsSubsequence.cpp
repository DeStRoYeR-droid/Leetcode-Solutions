// Last updated: 13/07/2026, 22:20:19
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int i = 0;
        for (const char& ch : t){
            if (i == n) break;
            if (ch == s[i]) ++i;
        }
        return i == n;
    }
};