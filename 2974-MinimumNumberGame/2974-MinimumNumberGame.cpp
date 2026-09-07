// Last updated: 07/09/2026, 22:39:34
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 2){
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};