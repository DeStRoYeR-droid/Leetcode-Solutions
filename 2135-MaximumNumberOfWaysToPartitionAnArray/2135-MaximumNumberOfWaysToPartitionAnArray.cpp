// Last updated: 06/07/2026, 18:59:36
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        const int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        unordered_map<long long, int> left, right;

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i-1] + nums[i];

        for (int i = 0; i < n-1; ++i) {
            long long diff = prefix[i] - (total - prefix[i]);
            right[diff]++;
        }

        int result = right[0];
        for (int i = 0; i < n; ++i){
            long long diff = k - nums[i];
            int cur = 0;
            if (diff != 0){
                cur = left[diff] + right[-diff];
                result = max(result, cur);
            }
            if (i < (n - 1)){
                long long d = prefix[i] - (total - prefix[i]);
                right[d]--;
                left[d]++;
            }
        }
        return result;
    }
};