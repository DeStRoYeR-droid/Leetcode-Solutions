// Last updated: 13/07/2026, 22:25:40
class Solution {
public:
    int maxProduct(const vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;

        for (const int& n : nums){
            int temp = curMax * n;
            curMax = max({temp, curMin * n, n});
            curMin = min({temp, curMin * n, n});

            result = max(result, curMax);
        }

        return result;
    }
};