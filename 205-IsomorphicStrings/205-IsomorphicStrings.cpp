// Last updated: 13/07/2026, 22:23:53
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashset;
        int length = s.length();
        for (int i = 0; i < length; i++){
            if (hashset.find(s[i]) == hashset.end()) hashset[s[i]] = t[i];
            else{
                if (hashset[s[i]] != t[i]) return false;
            }
        }
        hashset.clear();
        for (int i = 0; i < length; i++){
            if (hashset.find(t[i]) == hashset.end()) hashset[t[i]] = s[i];
            else{
                if (hashset[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};