// Last updated: 06/07/2026, 18:48:27
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