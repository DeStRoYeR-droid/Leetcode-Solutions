// Last updated: 30/08/2026, 15:12:45
static const int MOD = 1e9 + 7;

long long binpow(long long a, long long b, long long m = MOD) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        int result = 0;
        for (const long long& val : nums){
            long long width = val % 10;
            string s = to_string(val);

            long long base = 0, exponent = 0;
            for (int i = 0; i < width; ++i){
                base = base * 10 + (s[i] - '0');
            }
            for (int i = width; i < s.size() - 1; ++i){
                exponent = exponent * 10 + (s[i] - '0');
            }
            result = (result + binpow(base, exponent)) % MOD;
        }
        return result;
    }
};