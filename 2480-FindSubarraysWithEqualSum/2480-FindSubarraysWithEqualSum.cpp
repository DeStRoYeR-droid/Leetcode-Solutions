// Last updated: 06/07/2026, 18:56:49
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n - 2; ++i){
            int val = nums[i] + nums[i + 1];
            for (int j = i + 1; j < n - 1; ++j){
                if (nums[j] + nums[j + 1] == val) return true;
            }
        }
        return false;
    }
};