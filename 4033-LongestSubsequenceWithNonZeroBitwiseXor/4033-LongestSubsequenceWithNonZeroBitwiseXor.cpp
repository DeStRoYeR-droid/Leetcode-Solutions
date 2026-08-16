// Last updated: 16/08/2026, 13:52:01
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0, nonZero = 0;
        
        for (auto& n : nums){
            total ^= n;
            nonZero |= n > 0;
        }
        return nonZero * (nums.size() - !total);
    }
};