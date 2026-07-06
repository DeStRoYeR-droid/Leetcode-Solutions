// Last updated: 06/07/2026, 18:50:54
class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        if (k == 0) return true;
        int n = s.size();
        vector<int> first(128, -1), last(128, -1);
        for (int i = 0; i < n; i++) {
            if (first[s[i]] == -1) first[s[i]] = i;
            last[s[i]] = i;
        }

        vector<pair<int,int>> intervals;

        for (int c = 0; c < 128; c++) {
            if (first[c] == -1) continue;
            int start = first[c], end = last[c];
            bool valid = true;

            for (int i = start; i <= end; i++) {
                char d = s[i];
                if (first[d] < start) { valid = false; break; }
                end = max(end, last[d]);
            }

            if (valid && (start > 0 || end < n - 1)) {
                intervals.push_back({start, end});
            }
        }

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){ return a.second < b.second; });

        int count = 0, prevEnd = -1;
        for (auto &it : intervals) {
            if (it.first > prevEnd) {
                count++;
                prevEnd = it.second;
                if (count >= k) return true;
            }
        }
        return false;
    }
};