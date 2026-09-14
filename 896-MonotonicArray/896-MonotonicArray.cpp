// Last updated: 14/09/2026, 09:32:40
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