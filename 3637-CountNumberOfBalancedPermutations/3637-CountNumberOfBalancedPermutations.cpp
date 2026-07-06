// Last updated: 06/07/2026, 18:51:49
class Solution {
private:
    static const int mod = 1e9 + 7;
    vector<long long> fact, inv, invFact;

    void precompute(int n){
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % mod;
        
        inv.assign(n + 1, 1);
        for (int i = 2; i <= n; ++i)
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;

        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            invFact[i] = invFact[i-1] * inv[i] % mod;
    }
public:
    int countBalancedPermutations(string num) {
        const int n = num.size();
        int total = 0;
        for (const char& ch : num) total += ch - '0';
        if (total % 2) return 0;

        precompute(n);
        
        int halfTotal = total / 2;
        int halfLen = n / 2;

        vector<vector<int>> dp(halfTotal + 1, vector<int>(halfLen + 1));
        dp[0][0] = 1;

        vector<int> digits(10);
        for (const char& ch : num){
            int d = ch - '0';
            digits[d]++;

            for (int i = halfTotal; i >= d; --i){
                for (int j = halfLen; j > 0; --j){
                    dp[i][j] = (dp[i][j] + dp[i-d][j-1]) % mod;
                }
            }
        }

        long long result = dp[halfTotal][halfLen];
        result = result * fact[halfLen] % mod * fact[n - halfLen] % mod;
        for (int i : digits)
            result = result * invFact[i] % mod;

        return result;
    }
};