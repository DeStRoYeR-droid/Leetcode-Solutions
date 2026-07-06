// Last updated: 06/07/2026, 18:58:23
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long lo = 0, hi = total / n;

        while (lo < hi){
            long long mid = (lo + hi + 1) / 2;
            if (canRun(mid, n, batteries)){
                lo = mid;
            }
            else hi = mid - 1;
        }
        return lo;
    }

    bool canRun(long long time, int n, const vector<int>& batteries){
        long long contribution = 0;
        for (const int& b : batteries){
            contribution += min((long long)b, time);
            if (contribution >= (long long) n * time) return true;
        }
        return contribution >= (long long) n * time;
    }
};