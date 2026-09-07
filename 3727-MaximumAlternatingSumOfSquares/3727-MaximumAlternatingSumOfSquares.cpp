// Last updated: 07/09/2026, 22:25:16
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result = 0;
        for (auto& val : nums){
            val = val * val;
        }
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; --i){
            if (i >= nums.size() / 2) result += nums[i];
            else result -= nums[i];
        }
        return result;
    }
};