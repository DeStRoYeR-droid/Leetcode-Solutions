// Last updated: 24/08/2026, 22:35:42
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        if (n <= 2) return n;
        vector<int> occur(26, 0);
        int result = 2;
        for (int l = 0, r = 0; r < n; ++r){
            occur[s[r] - 'a']++;
            while (occur[s[r] - 'a'] > 2) occur[s[l++] - 'a']--;
            result = max(result, r - l + 1);
        }
        return result;
    }
};