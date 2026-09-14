// Last updated: 14/09/2026, 09:16:58
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long absDiff = abs(goal - total);
        return absDiff / limit + (absDiff % limit > 0);
    }
};