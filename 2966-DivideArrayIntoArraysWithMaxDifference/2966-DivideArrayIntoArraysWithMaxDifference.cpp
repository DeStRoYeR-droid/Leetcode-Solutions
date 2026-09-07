// Last updated: 07/09/2026, 22:39:17
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < n; i += 3){
            if (nums[i + 2] - nums[i] > k) return {};
            else result.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return result;
    }
};