// Last updated: 13/07/2026, 22:27:51
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> result = {{}};
        for (const int& val : nums){
            int n = result.size();
            for (int i = 0; i < n; ++i){
                vector<int> subset = result[i];
                subset.push_back(val);
                if (find(result.begin(), result.end(), subset) == result.end()){
                    result.push_back(subset);
                }
            }
        }
        return result;
    }
};