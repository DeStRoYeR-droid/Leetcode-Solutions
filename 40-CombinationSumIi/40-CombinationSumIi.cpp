// Last updated: 13/07/2026, 22:29:32
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        makeCombination(candidates, target, 0, curr, result);
        return result;
    }

    void makeCombination(const vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int>>& result){
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            curr.push_back(candidates[i]);
            makeCombination(candidates, target - candidates[i], i + 1, curr, result);
            curr.pop_back();
        }
    }
};