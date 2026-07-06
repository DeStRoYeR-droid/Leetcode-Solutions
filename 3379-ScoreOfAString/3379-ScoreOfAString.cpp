// Last updated: 06/07/2026, 18:53:15
class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for (int i = 0; i < s.size() - 1; ++i) result += abs(int(s[i]) - s[i + 1]);
        return result;
    }
};