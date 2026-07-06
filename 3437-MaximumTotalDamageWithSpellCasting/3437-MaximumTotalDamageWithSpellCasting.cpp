// Last updated: 06/07/2026, 18:52:58
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        const int n = power.size();
        sort(power.begin(), power.end());
        vector<pair<int, long long>> dp;

        int index = 0;
        while (index < n) {
            int potion = power[index];
            long long val = 0;
            while (index < n && power[index] == potion) {
                val += power[index];
                ++index;
            }
            dp.push_back({potion, val});
        }

        vector<long long> res(dp.size());
        res[0] = dp[0].second;
        int last_safe = -1;
        for (int i = 1; i < dp.size(); ++i) {
            while (last_safe + 1 < i && dp[i].first - dp[last_safe + 1].first >= 3)
                ++last_safe;
            long long take_cur = dp[i].second + (last_safe == -1 ? 0 : res[last_safe]);
            res[i] = max(res[i - 1], take_cur);
        }
        return res.back();
    }
};
