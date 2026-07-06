// Last updated: 06/07/2026, 18:51:11
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int n = startTime.size();
        vector<int> gap(n + 1);

        for (int i = 1; i < n; ++i){
            gap[i] = startTime[i] - endTime[i - 1];
        }
        gap[0] = startTime[0];
        gap[n] = eventTime - endTime[n - 1];

        int result = 0, total = accumulate(gap.begin(), gap.begin() + min(n, k) + 1, 0);
        result = max(result, total);

        int i = 0, j = k;
        while (j < n){
            total -= gap[i++]; 
            total += gap[++j];
            result = max(result, total);
        }

        return result;
    }
};