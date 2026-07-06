// Last updated: 06/07/2026, 18:47:37
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long result = LLONG_MIN;
        const int n = nums.size();
        vector<long long> prefix(n), suffix(n);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; ++i){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = n - 2; i >= 0; --i){
            suffix[i] = min(suffix[i + 1], (long long)nums[i]);
        }

        for (int i = 0; i < n - 1; ++i){
            result = max(result, prefix[i] - suffix[i + 1]);
        }
        return result;
    }
};