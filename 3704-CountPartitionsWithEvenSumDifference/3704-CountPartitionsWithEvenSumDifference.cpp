// Last updated: 06/07/2026, 18:51:22
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 0) return nums.size() - 1;
        else return 0;
    }
};