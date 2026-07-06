// Last updated: 06/07/2026, 18:49:02
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;
        for (const auto& num : nums){
            if (!(num & 1)) result |= num;
        }
        return result;
    }
};