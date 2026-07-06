// Last updated: 06/07/2026, 18:48:33
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int result = 0, sign = 1;
        for (const auto& val : nums){
            result += sign * val;
            sign = sign * -1;
        }
        return result;
    }
};