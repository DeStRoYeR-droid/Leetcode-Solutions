// Last updated: 06/07/2026, 18:49:50
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        if (nums.size() <= 2) return llabs(accumulate(nums.begin(), nums.end(), 0LL));
        long long sumA = 0;
        long long sumB = accumulate(nums.begin(), nums.begin() + 2, 0LL);

        vector<int> primes;
        for (int i = 2; i < nums.size(); ++i){
            bool isPrime = true;
            for (const int& val : primes){
                if (val * val > i) break;
                if (i % val == 0){
                    isPrime = false;
                    break;
                }
            }

            sumA += (isPrime) ? nums[i] : 0;
            sumB += (!isPrime) ? nums[i] : 0;
            
            if (isPrime) primes.push_back(i);
        }
        return abs(sumA - sumB);
    }
};