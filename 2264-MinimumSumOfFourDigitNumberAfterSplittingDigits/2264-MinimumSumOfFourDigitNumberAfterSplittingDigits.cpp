// Last updated: 06/07/2026, 18:58:22
class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        while (num >= 10){
            int cur = num % 10;
            nums.push_back(cur);
            num = num / 10;
        }
        nums.push_back(num);
        sort(nums.begin() , nums.end());

        return nums[0] * 10 + nums[3] + nums[1] * 10 + nums[2];
    }
};