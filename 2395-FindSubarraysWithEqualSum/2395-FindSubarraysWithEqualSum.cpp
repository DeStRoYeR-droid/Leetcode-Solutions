// Last updated: 07/09/2026, 22:45:45
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