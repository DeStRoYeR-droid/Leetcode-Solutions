// Last updated: 07/09/2026, 22:32:24
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