// Last updated: 14/09/2026, 09:14:29
class Solution {
public:
    bool isThree(int n) {
        int divisor = 2;
        for (int i = 2; i <= n / 2; ++i){
            if (divisor > 3) return false;
            if (n % i == 0) ++divisor;
        }
        return divisor == 3;
    }
};