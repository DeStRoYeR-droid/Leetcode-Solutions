// Last updated: 06/07/2026, 18:51:17
class Solution {
private:
    vector<vector<int>> DIRS = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(8, 0)));

        int result = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] != 1) continue;
                vector<int> maxs = {m - i, j + 1, i + 1, n - j};
                for (int k = 0; k < 4; ++k){
                    if (maxs[k] > result){
                        result = max(result, dfs(i, j, k, 1, 2, grid, memo) + 1);
                    }
                }
            }
        }
        return result;
    }

    int dfs(int i, int j, int k, int canTurn, int target, vector<vector<int>>& grid, vector<vector<vector<int>>>& memo){
        i += DIRS[k][0];
        j += DIRS[k][1];

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != target) return 0;

        int mask = (k << 1) | canTurn;
        if (memo[i][j][mask] > mask) return memo[i][j][mask];

        int result = dfs(i, j, k, canTurn, 2 - target, grid, memo);
        if (canTurn == 1){
            vector<int> maxs = {(int)grid.size() - i - 1, j, i, (int)grid[0].size() - j - 1};
            int nk = (k + 1) % 4;
            if (maxs[nk] > result) result = max(result, dfs(i, j, nk, 0, 2 - target, grid, memo));
        }
        return memo[i][j][mask] = result + 1;
    }
};