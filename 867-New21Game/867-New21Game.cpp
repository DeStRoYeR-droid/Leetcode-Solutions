// Last updated: 06/07/2026, 19:07:55
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1);
        dp[0] = 1.0;

        double mxSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; ++i){
            dp[i] = mxSum / maxPts;
            if (i < k) mxSum += dp[i];
            else result += dp[i];

            if (i - maxPts >= 0) mxSum -= dp[i - maxPts];
        }
        return result;
    }
};