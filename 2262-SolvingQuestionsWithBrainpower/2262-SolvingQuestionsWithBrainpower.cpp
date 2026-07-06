// Last updated: 06/07/2026, 18:58:25
class Solution {
    long long dp[100001];
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();
        
        dp[n-1] = questions[n-1][0];
        for (int i = n - 2; i >= 0; --i){
            int nextTake = i + questions[i][1] + 1;
            if (nextTake >= n) dp[i] = max((long long)questions[i][0], dp[i+1]);
            else dp[i] = max((long long)questions[i][0] + dp[nextTake], dp[i+1]);
        }
        return dp[0];
    }
};