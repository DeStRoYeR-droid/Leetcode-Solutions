// Last updated: 13/07/2026, 22:26:10
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const int& val : nums) result = result ^ val;
        return result;
    }
};