// Last updated: 07/09/2026, 22:23:06
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        const int n = nums.size();
        int r = n - 2;
        while (r >= 0){
            if (nums[r + 1] <= nums[r]) break;
            else --r;
        }
        return r + 1;
    }
};