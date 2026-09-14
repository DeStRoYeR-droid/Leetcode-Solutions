// Last updated: 14/09/2026, 09:14:46
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