// Last updated: 13/07/2026, 22:29:56
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_index = nums.size() - 2;
        int last_num = nums[nums.size() - 1];
        while (cur_index >= 0){
            if (nums[cur_index] == last_num){
                nums.erase(nums.begin() + cur_index);
            }
            else{
                last_num = nums[cur_index];
            }
            cur_index--;
        }
        return nums.size();
    }
};

