// Last updated: 06/07/2026, 19:05:31
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        dp[n - 1][n - 1] = {0, 1};
        
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {1, 1}};
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == n - 1 && j == n - 1) continue;
                if (board[i][j] == 'X') continue;
                
                int max_val = -1;
                int ways = 0;
                
                for (const auto& [di, dj] : dirs) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < n && nj < n && dp[ni][nj].first != -1) {
                        if (dp[ni][nj].first > max_val) {
                            max_val = dp[ni][nj].first;
                            ways = dp[ni][nj].second;
                        } else if (dp[ni][nj].first == max_val) {
                            ways = (ways + dp[ni][nj].second) % MOD;
                        }
                    }
                }
                
                if (max_val != -1) {
                    int val = (board[i][j] == 'E' || board[i][j] == 'S') ? 0 : board[i][j] - '0';
                    dp[i][j] = {max_val + val, ways};
                }
            }
        }
        
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};