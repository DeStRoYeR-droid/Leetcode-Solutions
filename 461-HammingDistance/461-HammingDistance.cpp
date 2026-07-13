// Last updated: 13/07/2026, 22:19:18
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};