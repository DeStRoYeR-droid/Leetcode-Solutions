// Last updated: 07/09/2026, 22:33:26
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