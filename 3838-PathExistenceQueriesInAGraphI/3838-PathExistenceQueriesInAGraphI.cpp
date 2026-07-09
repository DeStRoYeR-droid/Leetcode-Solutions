// Last updated: 09/07/2026, 23:55:54
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n, 0);
        int curr = 0;

        for (int i = 1; i < n; ++i){
            if (nums[i] - nums[i - 1] > maxDiff) ++curr;
            group[i] = curr;
        }

        vector<bool> result;
        result.reserve(n);

        for (const auto& q: queries){
            result.push_back(group[q[0]] == group[q[1]]);
        }
        return result;
    }
};