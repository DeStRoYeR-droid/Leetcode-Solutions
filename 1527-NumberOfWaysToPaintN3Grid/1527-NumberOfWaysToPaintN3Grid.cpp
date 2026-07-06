// Last updated: 06/07/2026, 19:03:20
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