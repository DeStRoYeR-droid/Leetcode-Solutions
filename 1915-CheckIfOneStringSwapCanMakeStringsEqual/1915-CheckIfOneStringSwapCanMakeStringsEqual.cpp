// Last updated: 06/07/2026, 19:00:48
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char, int> charset1;
        map<char, int> charset2;
        for (const char& ch : s1) charset1[ch]++;
        for (const char& ch : s2) charset2[ch]++;

        int diff = 0;
        for (int i = 0; i < 26; ++i){
            if (charset1['a' + i] != charset2['a' + i]) return false;
        }
        for (int i = 0; i < s1.size(); ++i){
            diff += (s1[i] != s2[i]);
        }
        return diff <= 2;
    }
};