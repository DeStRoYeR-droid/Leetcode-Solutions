// Last updated: 06/07/2026, 18:48:30
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        long long sum = 0, result = 0;

        unordered_map<long long, long long> mp;

        for (int i = 0; i < n; ++i){
            sum += nums[i];
            mp[sum % k]++;
            result += mp[sum % k] - 1;

            if (sum % k == 0) ++result;
        }

        for (int i = 0; i < n; ++i){
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) ++j;

            long long curr = 0;
            for (int l = i; l < j; ++l){
                curr += nums[l];
                if (curr % k == 0) result -= j - l - 1;
            }

            i = j - 1;
        }
        return result;
    }
};