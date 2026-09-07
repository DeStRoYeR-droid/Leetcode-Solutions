// Last updated: 07/09/2026, 22:23:42
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<pair<int, int>> pos;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] >= 0){
                pos.push_back({nums[i], i});
            }
        }
        if (pos.size() == 0) return nums;
        k = k % pos.size();

        for (int i = 0; i < pos.size(); ++i){
            nums[pos[(i - k + pos.size()) % pos.size()].second] = pos[i].first;
        }
        return nums;
    }
};