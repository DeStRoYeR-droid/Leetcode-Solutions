// Last updated: 07/09/2026, 22:24:12
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long rev = 0;
        long long result = 0;
        long long total = 0;

        while (n){
            int digit = n % 10;
            n /= 10;

            if (digit) rev = rev * 10 + digit;
            total += digit;
        }

        while (rev){
            result = result * 10 + rev % 10;
            rev /= 10;
        }
        
        return result * total;
    }
};