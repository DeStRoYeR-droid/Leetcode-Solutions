// Last updated: 07/09/2026, 22:39:51
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end()), left = 0, occur = 0;
        long long result = 0;

        for (int right = 0; right < nums.size(); ++right){
            occur += nums[right] == maxi;

            while (occur >= k){
                if (nums[left] == maxi) --occur;
                ++left;
            }

            result += left;
        }

        return result;
    }
};