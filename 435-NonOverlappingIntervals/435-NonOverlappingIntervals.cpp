// Last updated: 13/07/2026, 22:19:45
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){return v1[1] < v2[1];});
        int prev = 0;
        int count = 1;

        for (int i = 1; i < n; ++i){
            if (intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }
        return n - count;
    }
};