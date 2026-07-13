// Last updated: 13/07/2026, 22:26:16
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> isPalin;

    bool isPalindrome(const string& s, int i, int j){
        if (i >= j) return true;
        if (isPalin[i][j] != -1) return isPalin[i][j];
        if (s[i] == s[j]) return isPalin[i][j] = isPalindrome(s, i + 1, j - 1);
        return isPalin[i][j] = false;
    }

    int solve(const string& s, int l, int r){
        if (l >= r) return dp[l][r] = 0;
        if (dp[l][r] != -1) return dp[l][r];
        if (isPalindrome(s, l, r)) return dp[l][r] = 0;
        int result = INT_MAX;
        for (int i = l; i <= r - 1; ++i){
            if (isPalindrome(s, l, i)) result = min(result, 1 + solve(s, i + 1, r));
        }
        return dp[l][r] = result;
    }
    
    int minCut(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));    
        isPalin.resize(s.size(), vector<int>(s.size(), -1));
        return solve(s, 0, s.size() - 1);    
    }
};