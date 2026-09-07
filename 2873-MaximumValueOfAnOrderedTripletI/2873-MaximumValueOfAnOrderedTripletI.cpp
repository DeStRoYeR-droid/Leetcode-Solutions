// Last updated: 07/09/2026, 22:40:18
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