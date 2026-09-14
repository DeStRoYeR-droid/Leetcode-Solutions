// Last updated: 14/09/2026, 09:24:23
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int result = 0;
        for (int i = 0; i < s.size(); i++){
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
                result += 1 + *min_element(lastSeen.begin(), lastSeen.end());
        }
        return result;
    }
};