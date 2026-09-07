// Last updated: 07/09/2026, 22:24:32
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int result = 0;
        for (const auto& val : nums) result += maxi - val;
        return result;
    }
};