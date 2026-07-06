// Last updated: 06/07/2026, 18:50:42
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        for (auto& p : conflictingPairs){
            if (p[0] > p[1]) swap(p[0], p[1]);
        }

        sort(conflictingPairs.begin(), conflictingPairs.end(),
        [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        long long blocked = 0;
        long long profit = 0;
        long long maxProfit = 0;
        int max1 = 0;
        int max2 = 0;
        int m = conflictingPairs.size();

        for (int i = 0; i < m; ++i){
            int start = conflictingPairs[i][0];
            int end = conflictingPairs[i][1];

            int nextEnd = (i + 1 < m) ? conflictingPairs[i + 1][1] : n + 1;
            int gap = nextEnd - end;

            if (start > max1){
                max2 = max1;
                max1 = start;
                profit = 0;
            }
            else if (start > max2){
                max2 = start;
            }

            profit += (long long)(max1 - max2) * gap;
            if (profit > maxProfit) maxProfit = profit;
            blocked += (long long)max1 * gap;
        }

        long long total = (long long)n * (n + 1) / 2;
        return total - blocked + maxProfit;
    }
};