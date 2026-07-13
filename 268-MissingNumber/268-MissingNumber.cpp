// Last updated: 13/07/2026, 22:21:55
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int curSum = accumulate(nums.begin(), nums.end(), 0);
        int expected = (nums.size() * (nums.size() + 1)) / 2;
        return expected - curSum;
    }
};