// Last updated: 07/09/2026, 22:23:28
class Solution {
public:
    string reversePrefix(string s, int k) {
        string result = "";
        for (int i = k - 1; i >= 0; --i) result += s[i];
        for (int i = k; i < s.size(); ++i) result += s[i];
        return result;
    }
};