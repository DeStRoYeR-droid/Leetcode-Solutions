// Last updated: 06/07/2026, 18:54:09
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k = k % m;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (i % 2){
                    if (mat[i][(j + k) % m] != mat[i][j]) return false;
                }
                else{
                    if (mat[i][(j - k + m) % m] != mat[i][j]) return false;
                }
            }
        }
        return true;;
    }
};