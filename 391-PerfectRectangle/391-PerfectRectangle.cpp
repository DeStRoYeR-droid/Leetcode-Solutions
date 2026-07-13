// Last updated: 13/07/2026, 22:20:21
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> point;
        for (auto &p : rectangles) {
            int x = p[0], y = p[1], a = p[2], b = p[3];
            if (++point[{x, y}] == 0) point.erase({x, y});
            if (--point[{x, b}] == 0) point.erase({x, b});
            if (++point[{a, b}] == 0) point.erase({a, b});
            if (--point[{a, y}] == 0) point.erase({a, y});
        }
        return point.size() == 4 && point.begin()->second == 1;
    }
};