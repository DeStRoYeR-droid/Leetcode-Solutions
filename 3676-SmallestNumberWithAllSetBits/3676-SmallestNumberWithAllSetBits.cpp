// Last updated: 06/07/2026, 18:51:32
class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;
        while (result <= n) result = result << 1;
        return result - 1;
    }
};