// Last updated: 06/07/2026, 18:48:29
class Solution {
    map<pair<int, double>, int> memo;

public:
    int countSequences(vector<int>& nums, long long k, int j = 0, double val = 1.0) {
        if (j == nums.size()) {
            return abs(val - (double)k) < 1e-9; 
        }

        if (memo.count({j, val})) return memo[{j, val}];

        int result = 0;
        result += countSequences(nums, k, j + 1, val / nums[j]); // Divide
        result += countSequences(nums, k, j + 1, val * nums[j]); // Multiply
        result += countSequences(nums, k, j + 1, val);           // Skip

        return memo[{j, val}] = result;
    }
};