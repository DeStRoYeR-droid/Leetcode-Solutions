// Last updated: 13/07/2026, 22:20:22
class Solution {
public:
    int lastRemaining(int n) {
        int step = 0;
        int sum = 0;

        while (true) {
            if (n == 1) break;

            if (step % 2 == 1 && n % 2 == 0) {
                sum += (1 << step);
            }

            n /= 2;
            step++;
        }

        return (1 << step) - sum;
    }
};