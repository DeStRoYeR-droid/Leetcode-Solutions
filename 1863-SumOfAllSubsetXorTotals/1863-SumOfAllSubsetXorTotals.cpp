// Last updated: 14/09/2026, 09:16:04
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orAll = accumulate(nums.begin(), nums.end(), 0, bit_or<int>());
        int multiplier = 1 << (nums.size() - 1);
        return orAll * multiplier;
    }
};