// Last updated: 06/07/2026, 18:54:22
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = n * (n + 1) / 2;
        int divisible = m * (n / m) * (n / m + 1);
        return total - divisible;
    }
};