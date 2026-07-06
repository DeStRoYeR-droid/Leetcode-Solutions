// Last updated: 06/07/2026, 18:55:28
class Solution {
public:
    int minOperations(int n) {
        int result = 0;
        while (n > 0){
            if ((n & 3) == 3){
                ++n;
                ++result;
            }
            else {
                result += n & 1;
                n >>= 1;
            }
        }
        return result;
    }
};