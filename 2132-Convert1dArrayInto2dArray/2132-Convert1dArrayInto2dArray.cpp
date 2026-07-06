// Last updated: 06/07/2026, 18:59:26
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m*n) return vector<vector<int>>();
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        vector<vector<int>> solution(m, vector<int>(n, 0));
        for (int i = 0; i < original.size(); i++)
            solution[i / n][i % n] = original[i];
        return solution;
    }
};