// Last updated: 06/07/2026, 18:54:13
class Solution {
public:
    long long C3(long long n){
        return (n < 0) ? 0 : (n + 1) * (n + 2) / 2;
    }
    long long distributeCandies(int n, int limit) {
        return C3(n) - 3LL * C3(n - limit - 1) + 3LL * C3(n - 2 * (limit + 1)) - C3(n - 3*(limit + 1));
    }
};