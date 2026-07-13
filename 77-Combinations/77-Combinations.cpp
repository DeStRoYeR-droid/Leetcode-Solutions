// Last updated: 13/07/2026, 22:28:16
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> cur;

        helper(n, k, cur, result);
        return result;
    }

    void helper(int n, int k, vector<int>& cur, vector<vector<int>>& result, int start = 1){
        if (cur.size() == k){
            result.push_back(cur);
            return;
        }
        else{
            for (int i = start; i <= n; ++i){
                cur.push_back(i);
                helper(n, k, cur, result, i+1);
                cur.pop_back();
            }
        }
    }
};