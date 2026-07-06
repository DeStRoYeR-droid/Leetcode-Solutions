// Last updated: 06/07/2026, 18:49:06
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return (long long) k * (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
    }
};