// Last updated: 14/09/2026, 09:19:16
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int length = points.size();
        vector<int> x_coord;
        for (auto& point: points) x_coord.push_back(point[0]);

        sort(x_coord.begin() , x_coord.end());

        int res = 0;
        for (int i = 0; i < length-1; i++) res = max(res, x_coord[i+1] - x_coord[i]);
        
        return res;
    }
};