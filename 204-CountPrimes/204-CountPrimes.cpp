// Last updated: 13/07/2026, 22:23:55
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = false; primes[1] = false;
        for (int i = 2; i < n; ++i){
            if (primes[i]){
                for (int j = i * 2; j < n; j += i){
                    primes[j] = false;
                }
            }
        }
        return accumulate(primes.begin(), primes.end(), 0);
    }
};