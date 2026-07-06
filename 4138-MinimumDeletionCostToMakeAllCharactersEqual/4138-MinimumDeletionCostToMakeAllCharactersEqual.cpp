// Last updated: 06/07/2026, 18:47:50
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        const int n = s.size();
        vector<long long> dp(26, 0);
        for (int i = 0; i < n; ++i){
            dp[s[i] - 'a'] += cost[i];
        }
        long long total = accumulate(cost.begin(), cost.end(), 0LL);
        return total - *max_element(dp.begin(), dp.end());
    }
};