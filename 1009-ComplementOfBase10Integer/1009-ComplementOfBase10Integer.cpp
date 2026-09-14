// Last updated: 14/09/2026, 09:30:20
class Solution {
public:
    int bitwiseComplement(int n, int num = 1) {
        for (num = 1; num < n; num = num << 1 | 1);
        return num ^ n;
    }
};