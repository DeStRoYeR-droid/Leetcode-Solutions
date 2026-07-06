// Last updated: 06/07/2026, 18:51:35
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> mp(101, 0);
        for (int i = nums.size() - 1; i >= 0; --i){
            if (++mp[nums[i]] > 1) return (i + 3) / 3;
        }
        return 0;

    }
};