// Last updated: 06/07/2026, 18:54:35
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        static const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> result(n, vector<int>(m));

        long long pre = 1, suf = 1;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                result[i][j] = pre;
                pre = (pre * grid[i][j]) % MOD;
            }
        }

        for (int i = n - 1; i >= 0; --i){
            for (int j = m - 1; j >= 0; --j){
                result[i][j] = (result[i][j] * suf) % MOD;;
                suf = (suf * grid[i][j]) % MOD;
            }
        }
        return result;
    }
};