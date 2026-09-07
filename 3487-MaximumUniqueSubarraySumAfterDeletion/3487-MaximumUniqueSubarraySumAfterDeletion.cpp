// Last updated: 07/09/2026, 22:31:32
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        if (maxVal <= 0) return maxVal;
        
        vector<bool> seen(101, false);
        int value = 0;

        for (const auto& val : nums){
            if (val >= 0 && !seen[val]){
                seen[val] = true;
                value += val;
            }
        }
        return value;
    }
};