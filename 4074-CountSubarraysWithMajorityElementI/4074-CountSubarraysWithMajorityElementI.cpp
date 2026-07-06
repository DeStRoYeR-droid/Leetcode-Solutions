// Last updated: 06/07/2026, 18:48:23
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i){
            int found = 0;
            for (int j = i; j < n; ++j){
                found += (nums[j] == target);
                result += (found * 2) > (j - i + 1);
            }
        }
        return result;
    }
};