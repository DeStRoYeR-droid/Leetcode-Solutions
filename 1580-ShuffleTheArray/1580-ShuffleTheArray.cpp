// Last updated: 06/07/2026, 19:02:52
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2 * n);
        int index = 0;
        for (int i = 0; i <  n; ++i){
            result[index++] = nums[i];
            result[index++] = nums[n + i];
        }
        return result;
    }
};