// Last updated: 13/07/2026, 22:24:06
class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        char length = nums.size();
        if (length == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = (nums[0] > nums[1]) ? nums[0] : nums[1];

        for (int i = 2; i < length; i++){
            int temp = prev1;
            prev1 = max(prev1 , prev2 + nums[i]);
            prev2 = temp;
        }

        return prev1;
    }
};