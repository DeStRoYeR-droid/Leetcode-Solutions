// Last updated: 07/09/2026, 22:48:16
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int n = nums.size(); n > 1; --n){
            for (int i = 0; i < n - 1; ++i){
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};