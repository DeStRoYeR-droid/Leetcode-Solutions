// Last updated: 13/07/2026, 22:19:03
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n - 1) >= 0;
    }

    int helper(vector<int>& nums, int l, int r){
        if (l == r) return nums[l];

        int chooseL = nums[l] - helper(nums, l + 1, r);
        int chooseR = nums[r] - helper(nums, l, r - 1);

        return max(chooseL, chooseR);
    }
};