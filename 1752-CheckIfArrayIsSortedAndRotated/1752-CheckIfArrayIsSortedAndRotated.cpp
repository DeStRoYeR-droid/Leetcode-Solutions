// Last updated: 14/09/2026, 09:17:25
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