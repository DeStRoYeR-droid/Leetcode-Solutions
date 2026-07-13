// Last updated: 13/07/2026, 22:19:00
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        vector<int> result = {area, 1};
        for (int j = w; j >= 2; --j){
            if (area % j == 0){
                result = {area / j, j};
                break;
            }
        }
        return result;
    }
};