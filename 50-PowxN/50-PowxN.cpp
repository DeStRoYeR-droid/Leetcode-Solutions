// Last updated: 13/07/2026, 22:29:09
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return binExp(1 / x, llabs(n));
        if (n == 0) return 1.0;
        return binExp(x, n);
    }

    double binExp(double x, long long n){
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n % 2 == 1) return x * binExp(x, n - 1);
        double res = binExp(x, n / 2);
        return res * res;
    }
};