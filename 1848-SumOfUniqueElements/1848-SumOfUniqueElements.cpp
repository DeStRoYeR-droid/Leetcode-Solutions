// Last updated: 06/07/2026, 19:01:10
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