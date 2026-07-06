// Last updated: 06/07/2026, 18:48:05
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long mini1 = INT_MAX, mini2 = INT_MAX, maxi1 = INT_MIN, maxi2 = INT_MIN;
        for (const auto& val : nums){
            if (val < mini1){
                mini2 = mini1;
                mini1 = val;
            }
            else if (val < mini2) mini2 = val;

            if (val > maxi1){
                maxi2 = maxi1;
                maxi1 = val;
            }
            else if (val > maxi2) maxi2 = val;
        }

        long long maxPossible = max(
            mini2 * mini1, max(maxi1 * maxi2, -mini1 * maxi1)
        );
        return maxPossible * 100000;
    }
};