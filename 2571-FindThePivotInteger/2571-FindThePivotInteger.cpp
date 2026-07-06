// Last updated: 06/07/2026, 18:56:17
class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        for (int x = 1; x <= n; ++x) if (x * x == total) return x;
        return -1;
    }
};