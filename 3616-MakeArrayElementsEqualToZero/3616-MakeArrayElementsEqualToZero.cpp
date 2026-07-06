// Last updated: 06/07/2026, 18:52:08
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        const int n = nums.size();
        int result = 0, l = 0, r = 0;
        for (const int& val : nums) r += val;
        for (int i = 0; i < n; ++i){
            l += nums[i];
            r -= nums[i];

            if (nums[i] != 0) continue;
            if (l == r) result += 2;
            else if (abs(l - r) == 1) ++result;
        }
        return result;
    }
};