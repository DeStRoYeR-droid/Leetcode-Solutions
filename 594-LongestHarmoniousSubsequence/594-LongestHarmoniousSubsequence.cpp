// Last updated: 13/07/2026, 22:18:04
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const int& num : nums) freq[num]++;

        int result = 0;
        for (const auto& iter : freq){
            if (freq.count(iter.first + 1) != 0){
                result = max(result, iter.second + freq[iter.first + 1]);
            }
        }
        return result;
    }
};