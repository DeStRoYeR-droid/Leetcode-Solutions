// Last updated: 13/07/2026, 22:30:24
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k){
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) k--;
                else if (total < 0) j++;
                else { 
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j-1] && j < k){
                        j++;
                    }
                }
            }
        }
        return result;
    }
};