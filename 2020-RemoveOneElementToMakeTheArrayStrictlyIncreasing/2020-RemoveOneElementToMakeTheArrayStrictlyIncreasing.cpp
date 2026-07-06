// Last updated: 06/07/2026, 19:00:13
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        const int n = nums.size();
        // i denotes the index of the number we have to ignore
        for (int i = 0; i < n; ++i){            
            bool found = false;

            for (int j = 0; j < n - 1; ++j){
                if (found) break;
                if (i == j) continue;
                if (i == j + 1){
                    if (j + 2 < n && nums[j] >= nums[j + 2]) found = true;
                }
                else if (nums[j] >= nums[j + 1]) found = true;
            }
            if (!found) return true;
        }
        return false;
    }
};