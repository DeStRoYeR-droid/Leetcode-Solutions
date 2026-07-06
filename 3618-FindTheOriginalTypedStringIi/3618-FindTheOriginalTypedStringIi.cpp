// Last updated: 06/07/2026, 18:52:05
class Solution {
    static const int MOD = 1e9 + 7;
public:
    int possibleStringCount(string word, int k) {
        const int n = word.size();
        vector<int> groups;
        int i = 0;
        while (i < n){
            int j = i + 1;
            while (j < n && word[j] == word[j - 1]) ++j;
            groups.push_back(j - i);
            i = j;
        }

        long long total = 1;
        for (const int& g : groups) total = (total * g) % MOD;
        if (k <= groups.size()) return total;

        vector<int> dp(k, 0);
        dp[0] = 1;

        for (const int& g : groups){
            vector<int> newDP(k, 0);
            int windowSum = 0;
            for (int len = 0; len < k; ++len){
                if (len > 0) windowSum = (windowSum + dp[len - 1]) % MOD;
                if (len > g) windowSum = (windowSum - dp[len - g - 1] + MOD) % MOD; 
                newDP[len] = windowSum;
            }
            dp = move(newDP);
        }

        int invalid = 0;
        for (int len = 0; len < k; ++len){
            invalid = (invalid + dp[len]) % MOD;
        }
        return (total - invalid + MOD) % MOD;
    }
};