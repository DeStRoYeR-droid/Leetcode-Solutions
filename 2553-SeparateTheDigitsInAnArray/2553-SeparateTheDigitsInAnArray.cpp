// Last updated: 07/09/2026, 22:43:34
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int num : nums){
            vector<int> digits = getDigits(num);
            for (int i = digits.size() - 1; i >= 0; --i){
                result.push_back(digits[i]);
            }
        }
        return result;
    }
    vector<int> getDigits(int num){
        if (num == 0) return {0};
        vector<int> result;
        while (num){
            result.push_back(num % 10);
            num /= 10;
        }
        return result;
    }
};