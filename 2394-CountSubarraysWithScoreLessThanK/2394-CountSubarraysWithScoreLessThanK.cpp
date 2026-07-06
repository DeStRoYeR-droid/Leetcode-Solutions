// Last updated: 06/07/2026, 18:57:27
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int n = nums.size();
        int left = 0, right = 0;
        long long result = 0, curSum = 0;
        
        for (right; right < n; ++right){
            curSum += nums[right];
            while (curSum * (right - left + 1) >= k){
                curSum -= nums[left];
                ++left;
            }

            result += (right - left + 1);
        }
        
        return result;
    }
};