// Last updated: 13/07/2026, 22:20:24
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for (const char& ch : s) freq[ch - 'a']++;
        for (int i = 0; i < s.size(); ++i) if (freq[s[i] - 'a'] == 1) return i;
        return -1;
    }
};