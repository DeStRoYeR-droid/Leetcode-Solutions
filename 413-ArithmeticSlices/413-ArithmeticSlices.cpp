// Last updated: 13/07/2026, 22:19:59
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        
        int result = 0;
        int curr = 0;
        
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                curr += 1;
                result += curr;
            } else {
                curr = 0;
            }
        }
        
        return result;
    }
};