// Last updated: 13/07/2026, 22:29:36
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        makeCombination(candidates, target, 0, curr, 0, result);
        return result;
    }

    void makeCombination(const vector<int>& candidates, int& target, int idx, vector<int>& curr,  int total, vector<vector<int>>& result){
        if (total == target){
            result.push_back(curr);
            return;
        }
        
        if (total > target || idx >= candidates.size()) return;

        curr.push_back(candidates[idx]);
        makeCombination(candidates, target, idx, curr, total + candidates[idx], result);
        curr.pop_back();
        makeCombination(candidates, target, idx + 1, curr, total, result);
    }
};