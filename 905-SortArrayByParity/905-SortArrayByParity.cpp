// Last updated: 14/09/2026, 09:32:25
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for (const auto& val : nums) if (val % 2 == 0) result.push_back(val);
        for (const auto& val : nums) if (val % 2) result.push_back(val);
        return result;
    }
};