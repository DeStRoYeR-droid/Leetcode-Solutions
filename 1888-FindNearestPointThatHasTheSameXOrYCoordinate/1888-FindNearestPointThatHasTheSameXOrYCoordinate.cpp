// Last updated: 06/07/2026, 19:00:58
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int result = -1, dist = INT_MAX;
        for (int i = 0; i < points.size(); ++i){
            int nx = points[i][0];
            int ny = points[i][1];
            if (nx == x || ny == y){
                int curD = abs(nx - x) + abs(ny - y);
                if (curD < dist){
                    result = i;
                    dist = curD;
                }
            }
        }
        return result;
    }
};