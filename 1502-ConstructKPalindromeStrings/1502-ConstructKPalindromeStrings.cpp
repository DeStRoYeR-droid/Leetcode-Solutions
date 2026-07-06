// Last updated: 06/07/2026, 19:03:32
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        if (s.length() == k) return true;
        int map = 0;
        for (const char& ch : s) map ^= 1 << (ch - 'a');
        return (__builtin_popcount(map) <= k);
    }
};