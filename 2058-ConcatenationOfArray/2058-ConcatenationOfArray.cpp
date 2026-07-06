// Last updated: 06/07/2026, 18:59:53
class Solution {
public:
    vector<int> getConcatenation(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(2 * n);
        for (int i = 0; i < n; ++i){
            result[i] = nums[i];
            result[n + i] = nums[i];
        }
        return result;
    }
};