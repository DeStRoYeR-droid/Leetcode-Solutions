// Last updated: 07/09/2026, 22:25:43
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