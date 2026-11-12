// Last updated: 12/11/2026, 22:49:27
class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int result = 0;
        int i = 0;
        int n = nums.size();
        while (i < n){
            int j = i + 1;
            while (j < n && nums[i] == nums[j]){
                ++j;
                ++result;
            }
            i = j;
        }
        return result;
    }
};