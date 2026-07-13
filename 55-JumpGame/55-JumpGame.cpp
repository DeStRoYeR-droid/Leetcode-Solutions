// Last updated: 13/07/2026, 22:28:58
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        for (int i = 0; i < nums.size(); i++){
            if (cur < 0) return false;
            cur = max(cur, nums[i]);
            cur--;
        }
        return true;
    }
};