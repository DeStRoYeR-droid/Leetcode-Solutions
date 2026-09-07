// Last updated: 07/09/2026, 22:27:18
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = count(nums.begin(), nums.end(), nums[0]);
        if (cnt < nums.size()) return 1;
        return 0;
    }
};