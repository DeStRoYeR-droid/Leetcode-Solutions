// Last updated: 14/09/2026, 09:17:39
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