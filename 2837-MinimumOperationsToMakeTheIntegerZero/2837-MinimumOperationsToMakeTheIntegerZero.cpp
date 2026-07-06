// Last updated: 06/07/2026, 18:55:05
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int op = 1; op <= 32; ++op){
            long long left = (1LL * num1) - (1LL * op * num2);
            if (left < op) return -1;

            int b = __builtin_popcountll(left);
            if (op >= b) return op;
        }
        return -1;
    }
};