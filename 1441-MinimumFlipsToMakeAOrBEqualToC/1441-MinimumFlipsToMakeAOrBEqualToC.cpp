// Last updated: 06/07/2026, 19:04:11
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        bool aBit, bBit, cBit;
        for (int i = 0; i < 32; i++){
            aBit = (1 << i) & a;
            bBit = (1 << i) & b;
            cBit = (1 << i) & c;

            if (!cBit) result += aBit + bBit;
            else if (!aBit && !bBit) ++result;
        }
        return result;
    }
};