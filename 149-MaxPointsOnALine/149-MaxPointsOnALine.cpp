// Last updated: 13/07/2026, 22:25:45
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 2) return n;

        int result = 2;
        for (int i = 0; i < n; ++i){
            map<double, int> slopes;
            for (int j = i + 1; j < n; ++j){
                double dy = (double)(points[j][1] - points[i][1]);
                double dx = (double)(points[j][0] - points[i][0]);

                if (dx == 0) slopes[INT_MAX]++;
                else{
                    slopes[dy/dx]++;
                }
            }

            int maxi = 0;
            for (const auto& p : slopes) maxi = max(maxi, p.second + 1);
            result = max(maxi, result);
            slopes.clear();
        }
        return result;
    }
};