// Last updated: 07/09/2026, 22:32:44
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        const int n = nums.size();
        int result = 0;
        int left = -k;
        int right = k;
        for (int i = 0; i < n; ++i){
            bool goodLeft = (left >= 0) ? nums[i] > nums[left] : true;
            bool goodRight = (right < n) ? nums[i] > nums[right] : true;
            result += (goodLeft && goodRight) ? nums[i] : 0;
            left++;
            right++;
        }
        return result;
    }
};