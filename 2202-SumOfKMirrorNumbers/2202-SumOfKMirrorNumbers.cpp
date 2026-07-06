// Last updated: 06/07/2026, 18:58:54
class Solution {
public:
    long long kMirror(int k, int n) {
        long long result = 0;
        for (long long len = 1; n > 0; len *= 10){
            for (long long i = len; n > 0 && i < len * 10; ++i){
                long long p = createPalindrome(i, true);
                if (isPalindrome(p, k)){
                    result += p;
                    --n;
                }
            }

            for (long long i = len; n > 0 && i < len * 10; ++i){
                long long p = createPalindrome(i, false);
                if (isPalindrome(p, k)){
                    result += p;
                    --n;
                }
            }
        }
        return result;
    }

    long long createPalindrome(long long num, bool odd){
        long long x = num;
        if (odd) x /= 10;
        while (x > 0){
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    bool isPalindrome(long long num, const int& base){
        vector<int> digits;
        while (num > 0){
            digits.push_back(num % base);
            num /= base;
        }
        int i = 0, j = digits.size() - 1;
        while (i < j) 
            if (digits[i++] != digits[j--]) return false;
            
        return true;
    }
};