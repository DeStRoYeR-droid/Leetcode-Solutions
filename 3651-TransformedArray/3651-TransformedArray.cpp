// Last updated: 06/07/2026, 18:51:38
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i){
            int n_index = (nums[i] + i);
            while (n_index < 0) n_index += n;
            result[i] = nums[n_index % n];
        }
        return result;
    }
};