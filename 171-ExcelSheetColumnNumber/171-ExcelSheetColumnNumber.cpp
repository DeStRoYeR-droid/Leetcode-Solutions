// Last updated: 13/07/2026, 22:25:05
class Solution {
public:
    int titleToNumber(const string& columnTitle) {
        int result = 0;
        for (const char&  c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};