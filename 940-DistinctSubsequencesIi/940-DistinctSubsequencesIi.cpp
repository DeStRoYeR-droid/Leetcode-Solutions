// Last updated: 14/09/2026, 09:31:37
static const int MOD = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {
        long long dp = 1;
        vector<long long> last(26, 0);

        for (char c : s){
            int index = c - 'a';
            long long lastDp = dp;
            dp = (2 * dp - last[index] + MOD) % MOD;
            last[index] = lastDp;
        }
        return (dp - 1 + MOD) % MOD;
    }
};