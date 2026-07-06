// Last updated: 06/07/2026, 18:47:00
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        bool prime = true;
        for (int n : nums){
            if (isPrime(n) == prime);
            else{
                while (isPrime(n) != prime){
                    n += 1;
                    result += 1;
                }
            }
            prime = !prime;
        }
        return result;
    }
    int isPrime(int n){
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false;
        return true;
    }
};