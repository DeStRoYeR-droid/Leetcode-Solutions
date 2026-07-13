// Last updated: 13/07/2026, 22:17:52
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        const int n = nums.size();
        for (int i = 2; i < n; ++i){
            int l = 0, r = i - 1;
            while (l < r){
                if (nums[l] + nums[r] > nums[i]){
                    result += r - l;
                    --r;
                }
                else ++l;
            }
        }
        return result;
    }
};