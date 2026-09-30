// Last updated: 30/09/2026, 18:27:19
static const int MOD = 1e9 + 7;
class Solution {
public:
    long long power(long long a, long long b){
        long long result = 1;
        while (b > 0){
            if (b & 1) result = result * a % MOD;
            
            a = a * a % MOD;
            b >>= 1;
        }
        return result;
    }
    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int choose = k << 1;

        vector<long long> fact(total + 1);
        vector<long long> invfact(total + 1);

        fact[0] = 1;
        for (int i = 1; i <= total; ++i) fact[i] = fact[i - 1] * i % MOD;

        invfact[total] = power(fact[total], MOD - 2);
        for (int i = total; i > 0; --i){
            invfact[i - 1] = invfact[i] * i % MOD;
        }
        return ((fact[total] * invfact[choose]) % MOD * invfact[total - choose]) % MOD;
    }
};