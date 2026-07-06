// Last updated: 06/07/2026, 18:57:39
class Solution {
public:
    int percentageLetter(const string& s, const char& letter) {
        const int n = s.size();
        int count = 0;
        for (const char& ch : s) count += (ch == letter);
        return count * 100 / n;
    }
};