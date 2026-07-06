// Last updated: 06/07/2026, 18:54:26
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0, maxVal = 0, maxDiff = 0;
        for (long long num : nums){
            result = max(result, maxDiff * num);
            maxDiff = max(maxDiff, maxVal - num);
            maxVal = max(maxVal, num);
        }
        return result;
    }
};