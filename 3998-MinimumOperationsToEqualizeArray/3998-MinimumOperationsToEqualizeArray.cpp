// Last updated: 06/07/2026, 18:49:09
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = count(nums.begin(), nums.end(), nums[0]);
        if (cnt < nums.size()) return 1;
        return 0;
    }
};