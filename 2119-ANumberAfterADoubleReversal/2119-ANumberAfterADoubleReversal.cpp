// Last updated: 07/09/2026, 22:49:47
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0) return true;
        return num % 10 != 0;
    }
};