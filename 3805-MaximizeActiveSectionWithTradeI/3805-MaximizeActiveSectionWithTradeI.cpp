// Last updated: 28/07/2026, 23:01:41
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        const int n = s.size();
        int ones = 0;
        int best = 0;

        int prev0 = INT_MIN;

        for (int i = 0; i < n; ){
            int j = i + 1;
            while (j < n && s[j] == s[i]) ++j;
            int len = j - i;

            if (s[i] == '1') ones += len;
            else {
                best = max(best, prev0 + len);
                prev0 = len;
            }

            i = j;
        }
        return ones + best;
    }
};