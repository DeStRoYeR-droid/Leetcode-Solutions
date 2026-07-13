// Last updated: 13/07/2026, 22:29:20
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, result, 0);
        set<vector<int>> st(result.begin(), result.end());
        result.clear();
        for (const auto& val : st) result.push_back(val);
        return result;
    }

    void solve(vector<int>& nums, vector<vector<int>>& result, int index){
        if (index >= nums.size()){
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(nums, result, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};