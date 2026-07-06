// Last updated: 06/07/2026, 18:58:36
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0) return true;
        return num % 10 != 0;
    }
};