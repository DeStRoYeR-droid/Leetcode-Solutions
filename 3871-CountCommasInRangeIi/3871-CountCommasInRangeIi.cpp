// Last updated: 07/09/2026, 22:22:34
class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        if (n < 1000) return total;

        for (long long i = 1000; i <= n; i *= 1000){
            total += n - (i - 1);
        }
        return total;
    }
};