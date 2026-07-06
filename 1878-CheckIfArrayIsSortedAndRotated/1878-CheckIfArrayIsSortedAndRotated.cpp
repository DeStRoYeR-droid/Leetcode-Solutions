// Last updated: 06/07/2026, 19:01:02
class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        int inv = 0;
        for (int i = 0; i < n && inv <= 1; ++i)
            if (nums[i] > nums[(i+1) % n]) inv++;
        
        return inv <= 1;
    }
};