// Last updated: 06/07/2026, 19:01:08
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxPositive = INT_MIN;
        int curP = 0;
        int maxNegative = INT_MIN;
        int curN = 0;
        for (const int& num : nums){
            curP += num;
            curN -= num;
            if (curP < 0) curP = 0;
            if (curN < 0) curN = 0;
            maxPositive = max(maxPositive, curP);
            maxNegative = max(maxNegative, curN);
        }
        return max(maxPositive, maxNegative);
    }
};