// Last updated: 06/07/2026, 18:48:09
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; ++i){
            if (nums[i] >= nums[i - 1]) left[i] = left[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i){
            if (nums[i] <= nums[i + 1]) right[i] = right[i + 1] + 1;
        }

        int maxLength = *max_element(left.begin(), left.end());

        maxLength = max(maxLength, right[1] + 1);
        maxLength = max(maxLength, left[n - 2] + 1);


        for (int i = 1; i < n - 1; ++i){
            if (nums[i - 1] <= nums[i + 1]){
                int combined = left[i - 1] + right[i + 1] + 1;
                maxLength = max(maxLength, combined);
            }
            maxLength = max(maxLength, left[i - 1] + 1);
            maxLength = max(maxLength, right[i + 1] + 1);
        }
        return maxLength;
    }
};