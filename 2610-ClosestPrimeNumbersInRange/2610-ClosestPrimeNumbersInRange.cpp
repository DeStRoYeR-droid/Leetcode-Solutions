// Last updated: 06/07/2026, 18:56:02
class Solution {
public:
    bool isPrime(const int& n){
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for (int i = left; i <= right; i++){
            if (isPrime(i)) primes.push_back(i);
        }
        
        vector<int> result = {-1 , -1};
        
        if (primes.size() <= 1) return result;
        int gap = INT_MAX;
        
        for (int i = 1; i < primes.size(); i++){
            if ((primes[i] - primes[i-1]) < gap){
                result = {primes[i-1], primes[i]};
                gap = primes[i] - primes[i-1];
            }
        }
        return result;
    }
};