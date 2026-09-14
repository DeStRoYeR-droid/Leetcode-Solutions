// Last updated: 14/09/2026, 09:35:26
static vector<long long> v(1001, 0);
class Solution {
public:
    int numTilings(int n) {
        static const int modulo = 1e9 + 7;

        v[1] = 1;
        v[2] = 2;
        v[3] = 5;

        if (n <= 3) return v[n];
        for (int i = 4; i <= n; ++i){
            v[i] = 2 * v[i-1] + v[i-3];
            v[i] %= modulo;
        }
        return v[n];
    }
};