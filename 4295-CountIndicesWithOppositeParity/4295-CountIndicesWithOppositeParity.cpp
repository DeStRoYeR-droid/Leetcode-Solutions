// Last updated: 06/07/2026, 18:46:56
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n - 1; ++i){
            int val = 0;
            for (int j = i + 1; j < n; ++j){
                if ((nums[i] ^ nums[j]) & 1) ++val;
            }
            result[i] = val;
        }

        return result;
    }
};