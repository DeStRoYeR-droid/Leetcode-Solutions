// Last updated: 07/09/2026, 22:37:57
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int end1 = 0;
        
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[end1] > nums[i - 1]) {
                rotate(nums.begin() + end1 + 1, nums.begin() + i, nums.begin() + i + 1);
                end1++;
            }
        }
        return nums;
    }
};