// Last updated: 06/07/2026, 18:58:15
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < nums.size() - 1; ++i){
            for (int j = i + 1; j < nums.size(); ++j){
                if (nums[i] == nums[j] && (i * j) % k == 0) ++result;
            }
        }

        return result;
    }
};