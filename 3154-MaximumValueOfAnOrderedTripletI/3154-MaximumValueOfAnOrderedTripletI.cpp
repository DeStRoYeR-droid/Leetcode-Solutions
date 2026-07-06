// Last updated: 06/07/2026, 18:54:25
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0, maxElement = 0, maxDiff = 0;
        for (long long num : nums){
            result = max(result, maxDiff * num);
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, num);
        }
        return result;
    }
};