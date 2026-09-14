// Last updated: 14/09/2026, 09:24:49
class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        if (num % 2) return 1 + numberOfSteps(num - 1);
        return 1 + numberOfSteps(num / 2);
    }
};