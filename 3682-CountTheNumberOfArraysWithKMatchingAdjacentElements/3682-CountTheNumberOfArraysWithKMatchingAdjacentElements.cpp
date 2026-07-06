// Last updated: 06/07/2026, 18:51:28
static const int MOD = 1e9 + 7;

class Solution {
public:
    long long inverseMod(long long a, long long mod){
        long long result = 1;
        long long power = mod - 2;

        while (power){
            if (power & 1) result = result * a % mod;
            a = a * a % mod;
            power >>= 1;
        }
        return result;
    }

    int nCr(int n, int r){
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        long long result = 1;

        for (int i = 1; i <= r; ++i){
            result = result * (n - r + i) % MOD;
            result = result * inverseMod(i, MOD) % MOD;
        }
        return (int)result;
    }

    long long binExpo(long long a, long long b){
        long long result = 1;
        while (b){
            if (b & 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    int countGoodArrays(int n, int m, int k) {
        int i1 = (m * 1LL * binExpo(m - 1, n - (k + 1))) % MOD;
        return (i1 * 1LL * nCr(n - 1, k)) % MOD;    
    }
};