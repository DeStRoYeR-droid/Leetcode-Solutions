// Last updated: 13/07/2026, 22:23:40
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int minLen = INT_MAX, left = 0, curSum = 0;
        
        for (int right = 0; right < n; ++right){
            curSum += nums[right];
            while (curSum >= target){
                minLen = min(minLen, right - left + 1);
                curSum -= nums[left];
                ++left;
            }
        }


        return (minLen == INT_MAX) ? 0 : minLen;
    }
};