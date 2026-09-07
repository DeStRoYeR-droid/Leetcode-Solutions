// Last updated: 07/09/2026, 22:38:20
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