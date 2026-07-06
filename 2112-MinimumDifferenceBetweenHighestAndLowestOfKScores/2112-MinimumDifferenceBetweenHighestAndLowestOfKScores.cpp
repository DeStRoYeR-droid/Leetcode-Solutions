// Last updated: 06/07/2026, 18:59:31
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        for (int i = 0; i <= n - k; i++) {
            int diff = nums[i + k - 1] - nums[i];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};