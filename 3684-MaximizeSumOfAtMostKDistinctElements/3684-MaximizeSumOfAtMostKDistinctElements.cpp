// Last updated: 07/09/2026, 22:27:19
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