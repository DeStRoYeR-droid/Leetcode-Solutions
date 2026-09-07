// Last updated: 07/09/2026, 22:38:16
class Solution {
public:
    int minOperations(int k) {
        int a = sqrt(k);
        return a + (k - 1) / a - 1;
    }
};