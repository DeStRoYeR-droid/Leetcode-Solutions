// Last updated: 13/07/2026, 22:24:00
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left)
            right = right & (right - 1);
        return right;
    }
};