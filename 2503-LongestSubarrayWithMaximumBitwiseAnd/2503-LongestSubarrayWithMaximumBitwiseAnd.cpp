// Last updated: 06/07/2026, 18:56:39
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        int max_num = *max_element(nums.begin(), nums.end());
        int index = 0;
        while (index < nums.size()){
            int num = nums[index];
            if (num == max_num){
                int start = index;
                while (index < nums.size() && nums[index] == num){
                    index++;
                }
                result = max(result, index - start);
            }
            index++;
        }
        return result;
    }
};