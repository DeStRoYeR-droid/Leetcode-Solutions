// Last updated: 13/07/2026, 22:29:42
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};