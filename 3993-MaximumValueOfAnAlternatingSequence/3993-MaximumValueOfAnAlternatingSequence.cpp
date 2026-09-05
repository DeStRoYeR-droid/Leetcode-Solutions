// Last updated: 05/09/2026, 16:37:35
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        return (n == 1) ? s : s + m + (m - 1) * ((long long)(n - 2) / 2);
    }
};