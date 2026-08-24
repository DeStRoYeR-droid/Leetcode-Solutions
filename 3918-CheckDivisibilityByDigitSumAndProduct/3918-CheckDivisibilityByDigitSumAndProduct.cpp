// Last updated: 24/08/2026, 22:32:30
class Solution {
public:
    static auto checkDivisibility(int n) -> bool {
        int r1 = 0, r2 = 1;
        int c = n;
        while (c){
            r1 += c % 10;
            r2 *= c % 10;
            c /= 10;
        }
        return n % (r1 + r2) == 0;
    }
};