// Last updated: 13/07/2026, 22:22:13
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sMap(26, 0);
        for (const char& ch : s){
            sMap[ch - 'a']++;
        }
        for (const char& ch : t){
            sMap[ch - 'a']--;
        }
        for (int i = 0; i < 26; ++i) if (sMap[i] != 0) return false;
        return true;
    }
};