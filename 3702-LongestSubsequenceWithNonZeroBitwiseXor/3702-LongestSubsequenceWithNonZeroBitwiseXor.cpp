// Last updated: 07/09/2026, 22:26:32
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