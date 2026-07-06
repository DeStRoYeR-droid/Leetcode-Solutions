// Last updated: 06/07/2026, 19:03:30
class Solution {
public:
    string longestPrefix(string s) {
        if (s.size() == 1) return "";
        int ind = kmp(s);
        return s.substr(0, ind);
    }

    int kmp(const string& s){
        const int n = s.size();
        vector<int> lps(n);
        lps[0] = 0;

        int j = 0;
        for (int i = 1; i < n; ++i){
            int prev = lps[i - 1];
            while (prev > 0 && s[i] != s[prev]){
                prev = lps[prev - 1];
            }

            lps[i] = prev + (s[i] == s[prev]);
        }
        return lps[n - 1];
    }
};