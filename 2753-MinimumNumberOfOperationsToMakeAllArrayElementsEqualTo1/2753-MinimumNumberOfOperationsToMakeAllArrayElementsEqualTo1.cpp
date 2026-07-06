// Last updated: 06/07/2026, 18:55:17
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int cnt = 0;

        for (int x : nums) {
            if (x == 1) cnt++;
        }
        if (cnt) return n - cnt;

        int minSubLen = INT_MAX;
        for (int l = 0; l < n - 1; l++) {
            int g = nums[l];
            for (int r = l + 1; r < n; r++) {
                g = gcd(g, nums[r]);
                if (g == 1) {
                    minSubLen = min(minSubLen, r - l + 1);
                    break;
                }
            }
        }

        if (minSubLen == INT_MAX) return -1;
        return n + minSubLen - 2;
    }
};