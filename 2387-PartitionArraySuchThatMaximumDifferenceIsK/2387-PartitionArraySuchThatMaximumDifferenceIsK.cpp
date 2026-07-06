// Last updated: 06/07/2026, 18:57:32
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 1;
        int minVal = nums[0];
        for (const int& num : nums){
            if (num - minVal > k){
                ++result;
                minVal = num;
            }
        }
        return result;
    }
};