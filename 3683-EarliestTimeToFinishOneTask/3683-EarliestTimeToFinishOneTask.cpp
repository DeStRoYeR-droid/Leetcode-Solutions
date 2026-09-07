// Last updated: 07/09/2026, 22:26:48
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int result = INT_MAX;
        for (const auto& task : tasks) result = min(result, task[0] + task[1]);
        return result;
    }
};