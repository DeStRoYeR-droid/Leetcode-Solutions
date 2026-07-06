// Last updated: 06/07/2026, 18:48:59
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int result = INT_MAX;
        for (const auto& task : tasks) result = min(result, task[0] + task[1]);
        return result;
    }
};