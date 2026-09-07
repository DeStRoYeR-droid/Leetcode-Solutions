// Last updated: 07/09/2026, 22:47:49
class Solution {
public:
    int percentageLetter(const string& s, const char& letter) {
        const int n = s.size();
        int count = 0;
        for (const char& ch : s) count += (ch == letter);
        return count * 100 / n;
    }
};