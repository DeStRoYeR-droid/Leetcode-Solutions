// Last updated: 13/07/2026, 22:21:59
class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        if (n == 1) return true;
        n = abs(n);
        while (n % 2 == 0) n = n / 2;
        while (n % 3 == 0) n = n / 3;
        while (n % 5 == 0) n = n / 5;
        return n == 1;
    }
};