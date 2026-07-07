// Last updated: 07/07/2026, 16:09:55
static const int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i){
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> pref_val(n + 1, 0);
        vector<int> pref_cnt(n + 1, 0);
        vector<long long> pref_sum(n + 1, 0);

        for (int i = 0; i < n; ++i){
            int d = s[i] - '0';
            
            pref_sum[i + 1] = pref_sum[i] + d;
            pref_cnt[i + 1] = pref_cnt[i];
            pref_val[i + 1] = pref_val[i];

            if (d > 0) {
                pref_cnt[i + 1]++;
                pref_val[i + 1] = (pref_val[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            long long range_sum = pref_sum[r + 1] - pref_sum[l];
            int k = pref_cnt[r + 1] - pref_cnt[l];

            long long left_shifted = (pref_val[l] * pow10[k]) % MOD;
            long long x = (pref_val[r + 1] - left_shifted + MOD) % MOD;

            long long res = (x * (range_sum % MOD)) % MOD;
            ans.push_back(res);
        }

        return ans;
    }
};