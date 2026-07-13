// Last updated: 13/07/2026, 22:18:38
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            int remainder = k != 0 ? prefixSum % k : prefixSum;
    
            if (remainderIndex.find(remainder) != remainderIndex.end()) {
                if (i - remainderIndex[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndex[remainder] = i;
            }
        }
        return false;
    }
};