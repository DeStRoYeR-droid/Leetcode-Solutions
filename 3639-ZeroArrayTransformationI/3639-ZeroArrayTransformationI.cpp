// Last updated: 06/07/2026, 18:51:47
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        vector<int> diff(n+1);
        for (auto& q : queries){
            ++diff[q[0]];
            if (q[1] + 1 < n) --diff[q[1] + 1];
        }

        int total = 0;
        for (int i = 0; i < n; ++i){
            total += diff[i];
            if (nums[i] > total) return false;
        }
        return true;
    }
};