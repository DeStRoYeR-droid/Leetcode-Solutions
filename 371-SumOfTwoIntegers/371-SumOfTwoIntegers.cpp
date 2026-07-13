// Last updated: 13/07/2026, 22:20:38
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            unsigned carry = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};