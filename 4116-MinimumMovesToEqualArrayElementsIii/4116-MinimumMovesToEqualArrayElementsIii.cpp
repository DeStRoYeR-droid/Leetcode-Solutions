// Last updated: 06/07/2026, 18:47:59
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int result = 0;
        for (const auto& val : nums) result += maxi - val;
        return result;
    }
};