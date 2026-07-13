// Last updated: 13/07/2026, 22:18:36
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        else return max(a.size(), b.size());
    }
};