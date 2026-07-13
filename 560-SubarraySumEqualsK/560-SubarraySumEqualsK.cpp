// Last updated: 13/07/2026, 22:18:27
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + nums[i];

        unordered_map<int, int> mp;
        int result = 0;
        for (int i = 0; i < n; ++i){
            if (prefix[i] == k) ++result;
            if (mp.find(prefix[i] - k) != mp.end()) result += mp[prefix[i] - k];
            mp[prefix[i]]++;
        }
        return result;
    }
};