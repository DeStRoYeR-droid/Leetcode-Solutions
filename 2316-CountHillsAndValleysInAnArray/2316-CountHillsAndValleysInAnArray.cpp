// Last updated: 06/07/2026, 18:58:00
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
        int left = 0;

        for (int i = 1; i < nums.size() - 1; ++i){
            if (nums[i] != nums[i + 1]){
                if (nums[i] > nums[left] && nums[i] > nums[i + 1] ||
                    nums[i] < nums[left] && nums[i] < nums[i + 1]){
                        ++result;
                    }
                    left = i;
            }
        }
        return result;
    }
};