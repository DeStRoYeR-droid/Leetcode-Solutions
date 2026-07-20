// Last updated: 20/07/2026, 17:17:17
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        return (n == 1) ? s : s + m + (m - 1) * ((long long)(n - 2) / 2);
    }
};