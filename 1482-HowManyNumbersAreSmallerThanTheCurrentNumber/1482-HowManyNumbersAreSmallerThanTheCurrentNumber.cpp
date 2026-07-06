// Last updated: 06/07/2026, 19:03:40
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i){
            int val = 0;
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                if (nums[i] > nums[j]) ++val;
            }
            result[i] = val;
        }
        return result;
    }
};