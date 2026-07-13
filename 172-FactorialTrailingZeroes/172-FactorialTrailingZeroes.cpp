// Last updated: 13/07/2026, 22:25:03
class Solution {
public:
    int trailingZeroes(int n) {
        return n/5 + n/25 + n/125 + n/625 + n/3125;
    }
};