// Last updated: 13/07/2026, 22:17:08
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n){
            if ((n & 1) ^ (n & 2) == 0) return false;
            n >>= 1;
        }
        return true;
    }
};