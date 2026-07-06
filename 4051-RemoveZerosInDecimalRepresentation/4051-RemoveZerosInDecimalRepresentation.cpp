// Last updated: 06/07/2026, 18:48:44
class Solution {
public:
    long long removeZeros(long long n) {
        long long result = 0;
        int digits = 0;
        while (n){
            int digit = n % 10;
            if (digit){
                result = digit * pow(10, digits) + result;
                ++digits;
            }
            n /= 10;
        }
        return result;
    }
};