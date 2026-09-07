// Last updated: 07/09/2026, 22:36:16
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        for (int i = 0; i < nums.size() - 2; ++i){
            if (!nums[i]){
                for (int j = 0; j < 3; j++) nums[i+j] = !nums[i+j];
                // for (const int& num : nums) cout << num << " ";
                // cout << endl;
                operations++;
            }
        }

        for (int i = nums.size() - 3; i < nums.size(); ++i){
            if (nums[i] == 0) return -1;
        }
        return operations;
    }
};