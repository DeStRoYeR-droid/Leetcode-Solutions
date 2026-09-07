// Last updated: 07/09/2026, 22:52:14
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1, minEle = nums[0];
        for (const int& num : nums){
            if (num == minEle) continue;
            result = max(result, num - minEle);
            minEle = min(minEle, num);
        }
        return result;
    }
};