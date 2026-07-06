// Last updated: 06/07/2026, 18:51:07
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        const int n = nums.size();
        int result = INT_MIN;
        for (int i = 0; i <= n; ++i){
            result = max(result, abs(nums[i % n] - nums[(i + 1) % n]));
        }
        return result;
    }
};