// Last updated: 13/07/2026, 22:29:54
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j){
            if (nums[j] != val){
                if (i != j){
                    nums[i] = nums[j];
                }
                ++i;
            }
        }
        return i;
    }
};