// Last updated: 06/07/2026, 18:53:17
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int mini = -1, maxi = -1;

        for (int i = 0; i < nums.size(); ++i){
            if (isPrime(nums[i])){
                if (maxi == -1){
                    mini = i;
                    maxi = i;
                }
                maxi = i;
            }
        }
        return maxi - mini;
    }

    bool isPrime(const int& n){
        if (n <= 1) return false;
        int factors = 1;
        for (int i = 2; i < n; ++i){
            if (n % i == 0) ++factors;
        }
        return factors <= 1;
    }
};