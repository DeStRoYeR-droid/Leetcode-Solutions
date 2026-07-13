// Last updated: 13/07/2026, 22:17:23
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int last = INT_MIN;
        int result = 0, cur = 0;
        for (const int& val : nums){
            if (val > last) ++cur;
            else cur = 1;
            last = val;
            result = max(result, cur);
        }
        return result;
    }
};