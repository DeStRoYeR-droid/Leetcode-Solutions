// Last updated: 24/08/2026, 22:36:33
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        unordered_map<int, int> f;
        for (int l = 0, r = 0; r < n; ++r){
            int x = nums[r];
            auto it = f.find(x);
            int& freq = (it == f.end()) ? f[x] = 1: ++(it->second);
            while (freq > k) f[nums[l++]]--;

            result = max(result, r - l + 1);
        }

        return result;
    }
};