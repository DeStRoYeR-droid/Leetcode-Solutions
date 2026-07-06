// Last updated: 06/07/2026, 18:55:24
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n + 1, 0);
        vector<int> right(n + 1, 0);

        for (int i = 1; i <= n; ++i){
            left[i] += left[i - 1] + nums[i - 1];
        }
        for (int i = n - 1; i >= 0; --i){
            right[i] = right[i + 1] + nums[i];
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i){
            result[i] = abs(left[i+1] - right[i]);
        }
        return result;
    }
};