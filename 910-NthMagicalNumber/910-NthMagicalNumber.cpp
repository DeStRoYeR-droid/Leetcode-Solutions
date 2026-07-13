// Last updated: 13/07/2026, 22:15:21
class Solution {
public:
    static const int MOD = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long l = lcm(a, b);
        int c = l / a + l / b - 1;
        int k = (n - 1) / c;
        int result = 0;

        for (int i = 1, j = 1, need = n - k * c; need; --need){
            if (a * i < b * j) result = a * i++;
            else result = b * j ++;
        }

        return (k * l + result) % MOD;
    }
};