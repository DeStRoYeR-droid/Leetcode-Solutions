// Last updated: 07/09/2026, 22:43:27
class Solution {
public:
    long long coloredCells(int n) {
        long long result = n;
        return 1 + 2 * (result - 1) * result;
    }
};