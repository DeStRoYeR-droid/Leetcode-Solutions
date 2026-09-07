// Last updated: 07/09/2026, 22:33:19
class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;
        while (result <= n) result = result << 1;
        return result - 1;
    }
};