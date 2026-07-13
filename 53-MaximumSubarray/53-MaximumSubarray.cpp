// Last updated: 13/07/2026, 22:29:01
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i){
            cur += nums[i];
            result = max(result, cur);
            
            cur = max(0, cur);
        }
        return result;
    }
};