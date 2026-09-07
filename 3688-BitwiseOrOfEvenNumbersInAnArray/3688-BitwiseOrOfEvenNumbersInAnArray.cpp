// Last updated: 07/09/2026, 22:26:58
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