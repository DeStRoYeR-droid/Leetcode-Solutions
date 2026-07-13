// Last updated: 13/07/2026, 22:19:26
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        const int n = points.size();

        int end = points[0][1];
        int count = 1;
        for (int i = 1; i < n; ++i){
            if (points[i][0] > end){
                count++;
                end = points[i][1];
            }
            else end = min(end, points[i][1]);
        }

        return count;
    }
};