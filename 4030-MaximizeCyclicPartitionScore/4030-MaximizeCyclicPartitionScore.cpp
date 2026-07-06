// Last updated: 06/07/2026, 18:48:55
class Solution {
    long long maximumProfit(vector<int>& prices, int l, int r, int k) {
        int n = prices.size();
        vector<array<long long, 3>> f(k + 2, {LLONG_MIN / 2, LLONG_MIN / 2, LLONG_MIN / 2});
        for (int j = 1; j <= k + 1; j++) {
            f[j][0] = 0;
        }
        for (int i = l; i < r; i++) {
            int p = prices[i % n];
            for (int j = k + 1; j > 0; j--) {
                f[j][0] = max(f[j][0], max(f[j][1] + p, f[j][2] - p));
                f[j][1] = max(f[j][1], f[j - 1][0] - p);
                f[j][2] = max(f[j][2], f[j - 1][0] + p);
            }
        }
        return f[k + 1][0];
    }

public:
    long long maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int max_i = ranges::max_element(nums) - nums.begin();
        long long ans1 = maximumProfit(nums, max_i, max_i + n, k);
        long long ans2 = maximumProfit(nums, max_i + 1, max_i + 1 + n, k);
        return max(ans1, ans2);
    }
};