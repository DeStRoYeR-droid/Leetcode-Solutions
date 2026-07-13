// Last updated: 13/07/2026, 22:19:21
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        if (doubled.substr(1, doubled.size() - 2).find(s) != string::npos) return true;
        return false;
    }
};