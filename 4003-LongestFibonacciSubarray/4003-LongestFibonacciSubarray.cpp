// Last updated: 06/07/2026, 18:49:08
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 2;
        int i = 0;
        while (i < nums.size() - 2){
            if (nums[i] + nums[i + 1] == nums[i + 2]){
                int cur = 2;
                while (i < nums.size() - 2 && nums[i] + nums[i + 1] == nums[i + 2]){
                    ++cur;
                    ++i;
                }
                result = max(result, cur);
            }
            else ++i;
        }
        return result;
    }
};