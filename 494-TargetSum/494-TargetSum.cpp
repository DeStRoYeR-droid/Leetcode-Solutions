// Last updated: 13/07/2026, 22:18:56
class Solution {
public:
    int findWays(vector<int> &nums, int size, int target, vector<vector<int>> &dp, int &sum) {
        if (target == 0 && size == 0) {
            return 1;
        }
        if (size == 0 || target > sum || target < -sum) {
            return 0;
        }

        if (dp[size][target + sum] != -1) {
            return dp[size][target + sum];
        }

        int takeMinus = findWays(nums, size - 1, target + nums[size-1], dp, sum);
        int takePlus = findWays(nums, size - 1, target - nums[size-1], dp, sum);
        dp[size][target + sum] = takeMinus + takePlus;

        return dp[size][target + sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || target < -sum)
            return 0;

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2*sum+2, -1));
        return findWays(nums, n, target, dp, sum);
    }
};