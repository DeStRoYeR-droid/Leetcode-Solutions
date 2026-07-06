// Last updated: 06/07/2026, 18:52:33
using ll = long long;
class Solution {
public:
    ll minNumberOfSeconds(int height, vector<int>& times) {
        ll lo = 1, hi = 1e17;

        while (lo < hi) {
            ll mid = (lo + hi) >> 1;
            ll tot = 0;
            for (int i = 0; i < times.size() && tot < height; i++)
                tot += (ll)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);
            if (tot >= height)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};