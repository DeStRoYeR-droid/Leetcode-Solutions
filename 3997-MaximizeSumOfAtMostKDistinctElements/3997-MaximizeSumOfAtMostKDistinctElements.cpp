// Last updated: 06/07/2026, 18:49:11
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend(), greater<int>());
        vector<int> result;
        int curVal = 101, index = nums.size() - 1;
        while (result.size() < k && index >= 0){
            if (nums[index] != curVal){
                result.push_back(nums[index]);
                curVal = nums[index];
            }
            --index;
        }
        return result;
    }
};