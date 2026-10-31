// Last updated: 31/10/2026, 19:49:04
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        for (int i = 0; i <= (n + 1) / 2; ++i){
            if (s[i] == s[n - i - 1]) return i;
        }
        return -1;
    }
};