// Last updated: 06/07/2026, 19:01:27
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> seen;
        int left = 0, curSum = 0, maxSum = 0;

        for (int right = 0; right < n; ++right){
            while (seen.find(nums[right]) != seen.end()){
                curSum -= nums[left];
                seen.erase(nums[left]);
                ++left;
            }

            curSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};