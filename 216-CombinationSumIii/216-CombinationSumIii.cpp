// Last updated: 13/07/2026, 22:23:19
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        combination(k, n, 1, 0, {}, result);
        return result;
    }

    void combination(int k, int n, int ind, int sum, vector<int> temp, vector<vector<int>>& result){
        const int z = temp.size();
        if (sum == n && z == k){
            result.push_back(temp);
            return;
        }
        if (sum > n || ind > 9 || z > k) 
            return;
        sum += ind;
        temp.push_back(ind);
        combination(k, n, ind + 1, sum, temp, result);
        sum -= ind;
        temp.pop_back();
        combination(k, n, ind + 1, sum, temp, result);
    }
};