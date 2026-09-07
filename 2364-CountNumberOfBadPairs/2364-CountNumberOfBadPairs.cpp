// Last updated: 07/09/2026, 22:46:10
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