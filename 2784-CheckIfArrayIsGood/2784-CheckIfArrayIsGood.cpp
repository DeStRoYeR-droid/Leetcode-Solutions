// Last updated: 07/09/2026, 22:41:12
class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int n = nums.size();
        vector<int> mp(n, false);
        for (const int& val : nums){
            if (val > n - 1) return false;
            if (mp[val - 1] > 0 && val != n - 1) return false;
            if (mp[val - 1] > 1 && val == n - 1) return false;
            mp[val - 1]++;
        }
        return true;
    }
};