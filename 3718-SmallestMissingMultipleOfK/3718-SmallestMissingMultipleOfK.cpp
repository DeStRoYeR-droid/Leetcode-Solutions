// Last updated: 07/09/2026, 22:25:13
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int find = k;
        for (const auto& val : nums){
            if (val == find) find += k;
            else if (val > find) break;
        }
        return find;
    }
};