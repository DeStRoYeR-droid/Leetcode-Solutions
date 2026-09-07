// Last updated: 07/09/2026, 22:24:41
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - 1] + nums[n - 2] - nums[0];
    }
};