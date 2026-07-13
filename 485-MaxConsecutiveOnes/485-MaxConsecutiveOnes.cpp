// Last updated: 13/07/2026, 22:19:01
class Solution {
public:
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        int result = 0, cur = 0;
        for (const int& val : nums){
            cur = (val == 1) ? cur + 1 : 0;
            result = max(result, cur);
        }
        return result;
    }
};