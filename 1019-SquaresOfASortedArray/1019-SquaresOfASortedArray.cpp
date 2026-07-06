// Last updated: 06/07/2026, 19:06:34
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1, index = n - 1;
        while (left <= right){
            if (abs(nums[left]) >= abs(nums[right])){
                result[index--] = nums[left] * nums[left];
                left++;
            }
            else {
                result[index--] = nums[right] * nums[right];
                right--;
            }
        }

        return result;
    }
};