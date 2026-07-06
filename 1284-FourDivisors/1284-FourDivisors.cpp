// Last updated: 06/07/2026, 19:05:23
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (const int& val : nums){
            bool isValid = false;
            int divisors = 0;
            for (int i = 2; i * i <= val; ++i){
                if (val % i == 0){
                    if (isValid || i * i == val){
                        isValid = false;
                        break;
                    }
                    else {
                        isValid = true;
                        divisors = i + val / i;
                    }
                }
            }

            if (isValid){
                result += divisors + 1 + val;
            }
        }
        return result;
    }
};