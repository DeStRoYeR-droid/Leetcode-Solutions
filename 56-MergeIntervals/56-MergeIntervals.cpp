// Last updated: 13/07/2026, 22:28:56
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        vector<int> prev = intervals[0];
        
        for (int i = 0; i < intervals.size(); ++i){
            vector<int> cur = intervals[i];
            if (cur[0] <= prev[1]){
                prev[1] = max(prev[1], cur[1]);
            }
            else{
                result.push_back(prev);
                prev = cur;
            }
        }

        result.push_back(prev);
        return result;
    }
};