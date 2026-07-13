// Last updated: 13/07/2026, 22:19:25
class Solution {
public:
    int minMoves(vector<int>& nums) {
        const int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int mini = *min_element(nums.begin(), nums.end());
        return total - n * mini;
    }
};