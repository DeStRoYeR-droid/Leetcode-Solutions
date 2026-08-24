// Last updated: 24/08/2026, 22:35:55
class Solution {
public:
    int minOperations(int k) {
        int a = sqrt(k);
        return a + (k - 1) / a - 1;
    }
};