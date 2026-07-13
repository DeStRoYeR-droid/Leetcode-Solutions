// Last updated: 13/07/2026, 22:18:26
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size(); i += 2) result += nums[i];
        return result;
    }
};