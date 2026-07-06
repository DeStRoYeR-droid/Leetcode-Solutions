// Last updated: 06/07/2026, 18:57:40
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const int n = nums.size();
        int result = 0;
        long long left = accumulate(nums.begin() + 1, nums.end(), 0LL);
        long long right = nums[0];
        for (int i = 1; i < n; i++){
            if (right >= left) {result++;}
            right += nums[i];
            left -= nums[i];
        }
        return result;
    }
};