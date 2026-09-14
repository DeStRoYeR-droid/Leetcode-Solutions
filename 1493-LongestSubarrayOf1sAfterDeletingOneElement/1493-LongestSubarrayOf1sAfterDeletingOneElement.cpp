// Last updated: 14/09/2026, 09:21:25
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, result = 0, zeroCount = 0;
        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 0) zeroCount++;
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            result = max(result, right - left);
        }
        return result;
    }
};