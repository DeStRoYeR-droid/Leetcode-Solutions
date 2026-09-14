// Last updated: 14/09/2026, 09:26:01
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        int lx = points[0][0], ly = points[0][1], cx, cy;
        for (int i = 1; i < points.size(); ++i){
            cx = points[i][0], cy = points[i][1];
            result += max(abs(lx - cx), abs(cy - ly));;

            lx = cx;
            ly = cy;
        }
        return result;
    }
};