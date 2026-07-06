// Last updated: 06/07/2026, 18:55:43
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        const int n = weights.size();
        if (k == 1 || n == k) return 0;

        vector<long long> pairSum(n-1);
        for (int i = 0; i < n - 1; ++i) pairSum[i] = weights[i] + weights[i+1];

        sort(pairSum.begin(), pairSum.end());
        long long minScore = accumulate(pairSum.begin(), pairSum.begin() + (k - 1), 0LL);
        long long maxScore = accumulate(pairSum.end() - (k - 1), pairSum.end(), 0LL);

        return maxScore - minScore;
    }
};