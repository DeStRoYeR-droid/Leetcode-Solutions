// Last updated: 14/09/2026, 09:19:22
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while (n) {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
};