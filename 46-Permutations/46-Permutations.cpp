// Last updated: 13/07/2026, 22:29:22
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> picked(n, false);
        vector<vector<int>> result;
        vector<int> temp;
        helper(result, nums, temp, picked, n, 0);
        return result;
    }

    void helper(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, vector<bool>& picked, int& n, int curr){
        if (curr == n){
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < n; ++i){
            if (!picked[i]){
                picked[i] = true;
                temp.push_back(nums[i]);
                helper(result, nums, temp, picked, n, curr + 1);
                temp.pop_back();
                picked[i] = false;
            }
        }
    }
};