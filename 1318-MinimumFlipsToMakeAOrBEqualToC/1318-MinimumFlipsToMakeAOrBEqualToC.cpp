// Last updated: 14/09/2026, 09:24:57
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