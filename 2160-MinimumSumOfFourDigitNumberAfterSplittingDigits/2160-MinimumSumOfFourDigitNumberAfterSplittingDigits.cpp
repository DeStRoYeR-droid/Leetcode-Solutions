// Last updated: 07/09/2026, 22:49:15
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