// Last updated: 13/07/2026, 22:28:06
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return n;

        int result = 2;
        for (int i = 2; i < n; ++i){
            if (nums[i] != nums[result-2]){
                nums[result] = nums[i];
                result++;
            }
        }
        return result;
    }
};