// Last updated: 06/07/2026, 18:51:24
class Solution {
public:
    int countSubarrays(const vector<int>& nums, int result = 0) {
        for (int i = 0; i < nums.size() - 2; ++i){
            if (2 * (nums[i] + nums[i+2]) == nums[i+1]) ++result;
        }

        return result; 
    }
};