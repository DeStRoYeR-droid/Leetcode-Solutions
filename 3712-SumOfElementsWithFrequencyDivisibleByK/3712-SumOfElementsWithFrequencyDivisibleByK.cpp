// Last updated: 07/09/2026, 22:25:29
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (const int& val : nums) freq[val]++;
        int result = 0;
        for (const auto& p : freq) if (p.second % k == 0) result += p.first * p.second;
        return result;
    }
};