// Last updated: 13/07/2026, 22:20:25
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (const char& ch : t) result = result ^ ch;
        for (const char& ch : s) result = result ^ ch;
        return result;
    }
};