// Last updated: 07/09/2026, 22:27:07
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return (long long) k * (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
    }
};