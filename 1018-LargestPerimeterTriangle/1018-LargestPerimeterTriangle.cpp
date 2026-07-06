// Last updated: 06/07/2026, 19:06:36
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int n = nums.size();
        int a, b, c;
        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 2; --i){
            a = nums[i], b = nums[i - 1], c = nums[i - 2];
            if (b + c > a) return a + b + c;
        }
        return 0;
    }
};