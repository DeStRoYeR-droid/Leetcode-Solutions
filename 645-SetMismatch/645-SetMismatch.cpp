// Last updated: 13/07/2026, 22:17:39
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> found(n, false);
        vector<int> result(2, 0);

        for (auto& val : nums){
            if (found[val - 1]) result[0] = val;
            else found[val - 1] = true;
        }
        for (int i = 0; i < n; ++i) if (!found[i]) result[1] = i + 1;
        return result;
    }
};