// Last updated: 06/07/2026, 19:06:23
class Solution {
public:
    int bitwiseComplement(int n, int num = 1) {
        for (num = 1; num < n; num = num << 1 | 1);
        return num ^ n;
    }
};