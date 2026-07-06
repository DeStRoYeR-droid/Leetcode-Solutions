// Last updated: 06/07/2026, 19:04:56
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        vector<int> p0 = coordinates[0];
        vector<int> p1 = coordinates[1];

        int dx = p1[0] - p0[0];
        int dy = p1[1] - p0[1];

        for (int i = 2; i < coordinates.size(); i++) {

            vector<int> p = coordinates[i];

            int dx2 = p[0] - p0[0];
            int dy2 = p[1] - p0[1];

            int cross = dx * dy2 - dy * dx2;

            if (cross != 0) {
                return false;
            }
        }

        return true;
    }
};