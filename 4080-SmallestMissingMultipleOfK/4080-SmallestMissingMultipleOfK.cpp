// Last updated: 06/07/2026, 18:48:18
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int find = 1;
        for (const int& val : nums){
            if (val % k == 0 && val == k * find) ++find;
            else if (val > k * find) return k * find;
        }
        return k * find;
    }
};