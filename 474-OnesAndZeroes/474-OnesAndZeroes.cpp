// Last updated: 13/07/2026, 22:19:13
class Solution {
private:
    pair<int , int> getCnts(string& s) {
        int zeros = 0 , ones = 0;
        for (char ch : s) {
            if (ch == '0') zeros++;
            else ones++;
        }
        return {zeros , ones};
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , 0));

        for (string& s : strs) {
            pair<int , int> cost = getCnts(s);
            int cst0 = cost.first;
            int cst1 = cost.second;

            for (int i = m; i >= cst0; i--) {
                for (int j = n; j >= cst1; j--) {
                    dp[i][j] = max(dp[i][j] , 1 + dp[i - cst0][j - cst1]);
                }
            }
        }
        return dp[m][n];
    }
};