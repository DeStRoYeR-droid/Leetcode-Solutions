// Last updated: 13/07/2026, 22:27:55
class Solution {
    int dp[31][31][31];
public:
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));

        const int n = s1.size();
        return helper(s1, s2, 0, 0, n);
    }

    bool helper(const string& s1, const string& s2, int i, int j, int len){
        if (dp[i][j][len] != -1) return dp[i][j][len];

        if (s1.substr(i, len) == s2.substr(j, len)) return dp[i][j][len] = 1;
        
        vector<int> count(26, 0);
        for (int k = 0; k < len; ++k){
            count[s1[i + k] - 'a']++;
            count[s2[j + k] - 'a']--;
        }

        for (int k = 0; k < 26; ++k) if (count[k] != 0) return dp[i][j][len] = 0;

        for (int k = 1; k < len; ++k){
            if (helper(s1, s2, i, j, k) && helper(s1, s2, i + k, j + k, len - k))
                return dp[i][j][len] = 1;
            else if (helper(s1, s2, i, j + len - k, k) && helper(s1, s2, i + k, j, len - k))
                return dp[i][j][len] = 1;
        }
        return dp[i][j][len] = 0;
    }
};