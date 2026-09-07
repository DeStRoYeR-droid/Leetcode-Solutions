// Last updated: 07/09/2026, 22:47:27
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