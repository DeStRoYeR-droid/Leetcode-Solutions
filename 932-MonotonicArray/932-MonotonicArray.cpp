// Last updated: 06/07/2026, 19:07:21
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool decreasing = true, increasing = true;
        for (int i = 0; i < nums.size() - 1; ++i){
            if (nums[i] == nums[i + 1]) continue;
            if (nums[i] > nums[i + 1]) increasing = false;
            else decreasing = false;
        }
        return increasing || decreasing;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();