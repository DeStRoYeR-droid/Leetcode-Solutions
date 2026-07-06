// Last updated: 06/07/2026, 19:00:42
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int result = 1;
        for (const int& val : nums){
            if (val < 0) result *= -1;
            else if (val == 0) return 0;
        }
        return result;
    }
};