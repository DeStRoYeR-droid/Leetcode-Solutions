// Last updated: 06/07/2026, 18:59:54
#define ll long long
class Solution {
    static const int MOD = 1e9 + 7;

    ll exponentiation(ll base, ll exp){
        ll result = 1;
        while (exp > 0){
            if (exp % 2) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        return (exponentiation(5LL, (n + 1) / 2) * exponentiation(4LL, n / 2)) % MOD;;
    }
};