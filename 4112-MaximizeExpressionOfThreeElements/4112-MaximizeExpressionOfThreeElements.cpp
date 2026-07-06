// Last updated: 06/07/2026, 18:48:01
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - 1] + nums[n - 2] - nums[0];
    }
};