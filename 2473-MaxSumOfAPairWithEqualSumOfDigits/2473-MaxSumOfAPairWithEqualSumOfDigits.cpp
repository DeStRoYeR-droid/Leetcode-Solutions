// Last updated: 06/07/2026, 18:56:53
class Solution {
    vector<int> digits;
public:
    Solution() : digits(82, 0){}
    int getDigitSum(int num){
        int result = 0;
        do{
            result += num % 10;
            num = num / 10;
        } while (num > 0);
        return result;
    }

    int maximumSum(vector<int>& nums) {
        int result = -1;
        for (const int& num : nums){
            int digitSum = getDigitSum(num);
            if (digits[digitSum] != 0){
                result = max(result, digits[digitSum] + num);
            }
            digits[digitSum] = max(digits[digitSum], num);
        }
        return result;
    }
};
