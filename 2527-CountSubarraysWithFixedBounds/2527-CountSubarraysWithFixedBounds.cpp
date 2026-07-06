// Last updated: 06/07/2026, 18:56:29
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        long long start = -1, mini = -1, maxi = -1;

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] < minK || nums[i] > maxK) start = i;
            if (nums[i] == maxK) maxi = i;
            if (nums[i] == minK) mini = i;

            int valid = max(0LL, min(mini, maxi) - start);
            result += valid;
        }

        return result;
    }
};