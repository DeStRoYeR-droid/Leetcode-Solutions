// Last updated: 06/07/2026, 18:54:41
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> st1(26, 0), st2(26, 0);
        for (int i = 0; i < n; i += 2){
            st1[s1[i] - 'a']++;
            st1[s2[i] - 'a']--;
        }
        for (int i = 1; i < n; i += 2){
            st2[s1[i] - 'a']++;
            st2[s2[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; ++i){
            if (st1[i] != 0 || st2[i] != 0) return false;
        }
        return true;
    }
};