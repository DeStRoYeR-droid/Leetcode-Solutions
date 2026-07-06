// Last updated: 06/07/2026, 18:52:02
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, const int& k) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;
        int prev = INT_MIN >> 1;
        
        for (const int& val : nums) {
            int x = max(prev + 1, val - k);
            if (x <= val + k) {
                count++;
                prev = x;
            }
        }
        return count;
    }
};