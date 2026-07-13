// Last updated: 13/07/2026, 22:28:08
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < pow(2, n); ++i){
            vector<int> cur;
            for (int j = 0; j < n; ++j){
                if (i & (1 << j)) cur.push_back(nums[j]);
            }
            result.push_back(cur);
        }
        return result;
    }
};