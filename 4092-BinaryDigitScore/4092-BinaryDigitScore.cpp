// Last updated: 31/10/2026, 19:48:27
class Solution {
public:
    int calculateScore(int a, int b) {
        return (__builtin_popcount(a) >= __builtin_popcount(b)) ? __builtin_popcount(a) * __builtin_popcount(b) : __builtin_popcount(b) / __builtin_popcount(a);
    }
};