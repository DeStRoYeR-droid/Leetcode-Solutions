// Last updated: 06/07/2026, 18:59:10
class Solution {
public:
    int countMaxOrSubsets(const vector<int>& nums) {
        int maxVal = 0;
        for (const int& num : nums) maxVal |= num;
        return backtrack(nums, maxVal, 0, 0);
    }

    int backtrack(const vector<int>& nums, int maxVal, int index, int curVal){
        if (index == nums.size()){
            return (curVal == maxVal) ? 1 : 0;
        }
        if (curVal == maxVal){
            return 1 << (nums.size() - index);
        }
        return backtrack(nums, maxVal, index + 1, curVal | nums[index]) + backtrack(nums, maxVal, index + 1, curVal);
    }
};