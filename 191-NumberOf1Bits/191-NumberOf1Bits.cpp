// Last updated: 13/07/2026, 22:24:10
class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};