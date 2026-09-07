// Last updated: 07/09/2026, 22:46:15
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        while (true){
            int minPos = INT_MAX;
            for (const int& val : nums){
                if (val != 0) minPos = min(minPos, val);
            }

            if (minPos == INT_MAX) break;

            for (int i = 0; i < nums.size(); ++i) nums[i] = max(0, nums[i] - minPos);
            ++result;
        }
        return result;
    }
};