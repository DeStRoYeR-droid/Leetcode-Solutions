// Last updated: 13/07/2026, 22:20:57
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        return (n == pow(4, floor(log(n) / log(4))));
    }
};