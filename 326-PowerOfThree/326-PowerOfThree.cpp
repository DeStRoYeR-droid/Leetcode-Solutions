// Last updated: 13/07/2026, 22:21:15
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n >= 3){
            if (n % 3) break;
            n /= 3;
        }
        return n == 1;
    }
};