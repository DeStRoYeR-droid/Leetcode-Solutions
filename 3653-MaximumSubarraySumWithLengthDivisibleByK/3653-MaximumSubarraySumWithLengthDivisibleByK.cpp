// Last updated: 06/07/2026, 18:51:37
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long prefix = 0, subMax = LLONG_MIN;
        vector<long long> mini(k, LLONG_MAX / 2);
        mini[(k - 1) % k] = 0;

        for (int i = 0; i < nums.size(); ++i){
            prefix += nums[i];
            subMax = max(subMax, prefix - mini[i % k]);
            mini[i % k] = min(mini[i % k], prefix);
        }
        return subMax;
    }
};