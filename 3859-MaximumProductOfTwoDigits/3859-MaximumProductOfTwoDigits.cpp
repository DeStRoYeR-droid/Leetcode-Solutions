// Last updated: 28/07/2026, 23:01:19
class Solution {
public:
    int maxProduct(int n) {
        int m1 = 0, m2 = 0;
        while (n){
            int digit = n % 10; n /= 10;
            if (digit > m1){
                m2 = m1;
                m1 = digit;
            }
            else if (digit > m2){
                m2 = digit;
            }
        }
        return m1 * m2;
    }
};