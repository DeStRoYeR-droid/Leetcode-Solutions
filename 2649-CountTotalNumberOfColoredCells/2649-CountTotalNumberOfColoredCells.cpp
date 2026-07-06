// Last updated: 06/07/2026, 18:55:50
class Solution {
public:
    long long coloredCells(int n) {
        long long result = n;
        return 1 + 2 * (result - 1) * result;
    }
};