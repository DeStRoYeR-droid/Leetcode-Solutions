// Last updated: 05/09/2026, 16:37:54
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long result = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        while (mul > 0 && k > 0){
            result += nums[n] * (long long) mul;
            --mul;
            --k;
            --n;
        }

        while (k > 0){
            result += nums[n];
            --n; --k;
        }
        return result;
    }
};