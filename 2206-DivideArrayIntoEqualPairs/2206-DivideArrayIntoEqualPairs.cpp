// Last updated: 07/09/2026, 22:48:33
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) if (nums[i] != nums[i+1]) return false;
        return true;
    }
};