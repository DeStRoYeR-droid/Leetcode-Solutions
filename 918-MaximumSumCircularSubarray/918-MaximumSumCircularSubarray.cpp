// Last updated: 14/09/2026, 09:32:01
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, curMin = 0, curMax = 0;
        int maxSum = nums[0], minSum = nums[0];

        for (const int& num : nums){
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);

            total += num;
        }

        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};