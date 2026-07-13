// Last updated: 13/07/2026, 22:29:51
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        unsigned int ans = 0;
        int sign = (dividend > 0 == divisor > 0) ? 1 : -1;
        unsigned int n = abs(static_cast<long>(dividend)), d = abs(static_cast<long>(divisor));

        while (n >= d) {
            int count = 0;
            while (n > (d << (count + 1)))
                count++;
            n -= d << count;
            ans += 1 << count;
        }

        if (ans == (1 << 31) && sign == 1) return INT_MAX;

        return sign * ans;
    }
};