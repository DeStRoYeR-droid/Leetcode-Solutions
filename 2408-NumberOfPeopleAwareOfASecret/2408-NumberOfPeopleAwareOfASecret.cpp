// Last updated: 06/07/2026, 18:57:19
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        static const int MOD = 1e9 + 7;
        vector<long long> dp(n, 0);
        dp[0] = 1;

        long long total = 0, count = 0;
        for (int r = delay; r < n; ++r){
            total += dp[r - delay] - (r >= forget ? dp[r - forget] : 0);
            dp[r] = (total + MOD) % MOD;
            count += (r >= n - forget) ? total : 0;
        }
        count += (forget == n);
        return count % MOD;
    }
};