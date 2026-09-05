// Last updated: 05/09/2026, 16:37:27
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                long long gc = gcd(nums[i], nums[j]);
                result = max(result, ((long long)nums[i] * nums[j] / (gc * gc)));
            }
        }
        return result;
    }
};