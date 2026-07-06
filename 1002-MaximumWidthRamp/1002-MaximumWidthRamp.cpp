// Last updated: 06/07/2026, 19:06:43
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int n = nums.size();
        stack<int> s;

        for (int i = 0; i < n; ++i)
            if (s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        
        int width = 0;
        for (int j = n - 1; j >= 0; --j){
            while (!s.empty() && nums[s.top()] <= nums[j]){
                width = max(width, j - s.top());
                s.pop();
            }
        }
        return width;
    }
};