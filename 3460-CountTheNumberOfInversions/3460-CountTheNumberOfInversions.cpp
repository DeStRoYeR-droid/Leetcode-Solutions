// Last updated: 16/08/2026, 13:54:58
int dp[300][401];
static const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        map<int, int> m;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < requirements.size(); ++i){
            m[requirements[i][0]] = requirements[i][1];
        }

        if (m.find(0) != m.end() && m[0] != 0) return 0;

        return solve(1, n, m, 0);
    }

    int solve(int i, int n, map<int, int>& m, int cnt){
        if (i == n) return 1;
        if (cnt > 400) return 0;
        if (dp[i][cnt] != -1) return dp[i][cnt];

        int result = 0;
        for (int j = cnt; j <= cnt + i; ++j){
            if (m.find(i) != m.end()){
                if (j != m[i]) continue;
            }

            result = (result % MOD + solve(i + 1, n, m, j) % MOD) % MOD;
        }
        return dp[i][cnt] = result;
    }
};