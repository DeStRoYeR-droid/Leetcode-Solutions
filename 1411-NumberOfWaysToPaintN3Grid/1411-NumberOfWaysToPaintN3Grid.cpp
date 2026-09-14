// Last updated: 14/09/2026, 09:22:42
static const int MOD = 1e9 + 7;
class Solution {
public:
    int numOfWays(int n) {
        long long dpA = 6, dpB = 6;
        for (int i = 2; i <= n; ++i){
            long long newA = (dpA * 2 + dpB * 2) % MOD;
            long long newB = (dpA * 2 + dpB * 3) % MOD;
            dpA = newA;
            dpB = newB;
        }
        return (dpA + dpB) % MOD;
    }
};