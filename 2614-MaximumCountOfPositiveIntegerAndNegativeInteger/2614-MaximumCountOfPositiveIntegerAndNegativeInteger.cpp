// Last updated: 06/07/2026, 18:56:01
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countPos = 0, countNeg = 0;
        for (const int& num : nums) {
            countPos += (num > 0);
            countNeg += (num < 0);
        }
        return max(countPos, countNeg);
    }
};