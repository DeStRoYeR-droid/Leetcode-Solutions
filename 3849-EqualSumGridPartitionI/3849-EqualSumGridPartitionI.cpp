// Last updated: 06/07/2026, 18:50:19
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<long long> r(n, 0LL), c(m, 0LL);

        for (int i = 0; i < n; ++i){
            r[i] += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            for (int j = 0; j < m; ++j){
                c[j] += grid[i][j];
            }
        }

        long long rt = accumulate(r.begin(), r.end(), 0LL), ct = accumulate(c.begin(), c.end(), 0LL);
        long long rn = 0, cn = 0;

        for (int i = 0; i < n; ++i){
            rt -= r[i];
            rn += r[i];

            if (rt == rn) return true;
        }

        for (int i = 0; i < m; ++i){
            ct -= c[i];
            cn += c[i];

            if (ct == cn) return true;
        }

        return false;
    }
};