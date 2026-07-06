// Last updated: 06/07/2026, 19:06:44
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n - 2; ++i){
            if(nums[i] == nums[i+1] || nums[i] == nums[i+2]){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};