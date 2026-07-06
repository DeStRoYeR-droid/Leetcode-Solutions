// Last updated: 06/07/2026, 19:07:43
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        vector<int> m1(26, 0), m2(26, 0);
        int noMatch = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] != goal[i]) ++noMatch;
            m1[s[i] - 'a']++;
            m2[goal[i] - 'a']++;
        }
        if (noMatch > 2 || noMatch == 1) return false;

        bool canSwap = false;
        for (int i = 0; i < 26; ++i){
            if (m1[i] != m2[i]) return false;
            if (m1[i] == m2[i] && m1[i] >= 2) canSwap = true;
        }
        if (canSwap || noMatch == 2) return true;
        return false;
    }
};