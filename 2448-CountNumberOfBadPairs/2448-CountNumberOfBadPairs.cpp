// Last updated: 06/07/2026, 18:57:00
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const long long int n = nums.size();
        long long g = 0, k = 0;
        for (int i = 0; i < n; ++i){
            nums[i] = i - nums[i];
        }
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 1; ++i){
            if (nums[i] == nums[i+1]) k++;
            else{
                g = g + (k * (k + 1)) / 2;
                k = 0;
            }
        }

        return n * (n - 1) / 2 - g - k * (k + 1) / 2;
    }
};