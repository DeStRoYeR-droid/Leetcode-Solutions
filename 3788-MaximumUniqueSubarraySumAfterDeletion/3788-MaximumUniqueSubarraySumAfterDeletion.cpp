// Last updated: 06/07/2026, 18:50:43
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