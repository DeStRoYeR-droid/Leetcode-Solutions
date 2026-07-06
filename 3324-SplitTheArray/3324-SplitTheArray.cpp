// Last updated: 06/07/2026, 18:53:36
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const int& val : nums) freq[val]++;
        for (const auto& [_, f] : freq){
            if (f > 2) return false;
        }
        return true;
    }
};