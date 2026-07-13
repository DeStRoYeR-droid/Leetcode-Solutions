// Last updated: 13/07/2026, 22:16:33
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i){
            int bits = __builtin_popcount(i);
            if (isPrime(bits)) ++result;
        }
        return result;
    }

    bool isPrime(int num){
        if (num < 2) return false;
        for (int i = 2; i * i <= num; ++i) if (num % i == 0) return false;
        return true;
    }
};