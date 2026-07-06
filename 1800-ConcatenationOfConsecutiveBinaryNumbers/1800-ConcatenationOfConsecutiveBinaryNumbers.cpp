// Last updated: 06/07/2026, 19:01:31
class Solution {
public:
    int concatenatedBinary(int n) {
        static const int MOD = 1e9 + 7;

        long long result = 0;
        int bits = 0;

        for (int i = 1; i <= n; ++i){
            if ((i & (i - 1)) == 0) ++bits;
            result = ((result << bits) | i) % MOD;
        }
        return result;
    }
};