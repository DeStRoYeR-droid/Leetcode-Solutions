// Last updated: 06/07/2026, 18:56:52
class Solution {
public:
    int longestNiceSubarray(const vector<int>& nums) {
        const int n = nums.size();
        int result = 1;
        int left = 0;
        int used_bits = 0;

        for (int right = 0; right < n; ++right){
            while ((used_bits & nums[right]) != 0){
                used_bits ^= nums[left];
                ++left;
            }

            used_bits |= nums[right];
            result = max(result, right - left + 1);
        }
        return result;
    }
};