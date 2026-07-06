// Last updated: 06/07/2026, 19:00:24
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orAll = accumulate(nums.begin(), nums.end(), 0, bit_or<int>());
        int multiplier = 1 << (nums.size() - 1);
        return orAll * multiplier;
    }
};