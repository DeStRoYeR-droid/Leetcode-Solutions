// Last updated: 07/09/2026, 22:38:56
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = min(nums[1], nums[2]), min2 = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); ++i){
            if (nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2){
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    }
};