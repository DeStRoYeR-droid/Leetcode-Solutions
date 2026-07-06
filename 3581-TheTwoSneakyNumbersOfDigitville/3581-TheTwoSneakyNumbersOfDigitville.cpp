// Last updated: 06/07/2026, 18:52:21
class Solution {
public:
    vector<int> getSneakyNumbers(const vector<int>& nums) {
        const int n = nums.size() - 2;
        int value = 0;
        for (int i = 0; i < n; ++i) value ^= i;
        for (const auto& val : nums) value ^= val;
        
        value = value & -value;

        int xor1 = 0, xor2 = 0;
        for (const auto& val : nums){
            if (value & val) xor1 ^= val;
            else xor2 ^= val;
        }

        for (int i = 0; i < n; ++i){
            if (i & value) xor1 ^= i;
            else xor2 ^= i;
        }

        return {xor1, xor2};
    }
};