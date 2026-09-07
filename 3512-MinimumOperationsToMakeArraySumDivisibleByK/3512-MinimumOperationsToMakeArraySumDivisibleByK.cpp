// Last updated: 07/09/2026, 22:30:16
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};