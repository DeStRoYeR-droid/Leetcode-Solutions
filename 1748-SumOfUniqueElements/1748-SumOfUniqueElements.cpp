// Last updated: 14/09/2026, 09:17:40
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> f;
        for (const int& val: nums) f[val]++;
        int result = 0;
        for (const auto& [v, fre] : f) result += (fre == 1) ? v : 0;
        return result;
    }
};