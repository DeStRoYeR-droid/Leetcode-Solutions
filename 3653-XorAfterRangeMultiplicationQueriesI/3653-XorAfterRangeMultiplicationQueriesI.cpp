// Last updated: 07/09/2026, 22:27:58
static const int MOD = 1e9 + 7;
class Solution {
public:
    int xorAfterQueries(vector<int>& n, vector<vector<int>>& q) {
        for (auto &a : q) {
            for (int i = a[0]; i <= a[1]; i += a[2]) {
                n[i] = ((n[i] % MOD) * ((long long)a[3] % MOD)) % MOD;
            }
        }

        return accumulate(n.begin(), n.end(), 0, bit_xor<>());
    }
};