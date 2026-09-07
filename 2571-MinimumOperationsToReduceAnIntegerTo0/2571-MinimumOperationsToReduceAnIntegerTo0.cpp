// Last updated: 07/09/2026, 22:42:40
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