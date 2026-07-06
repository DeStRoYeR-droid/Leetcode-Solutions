// Last updated: 06/07/2026, 18:53:49
class Solution {
private:
    static bool cmp(vector<int>& p, vector<int>& q){
        return (p[0] == q[0]) ? p[1] < q[1] : p[0] > q[0];
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int n = points.size(), result = 0;
        
        for (int i = 0; i < n - 1; ++i){
            int y = INT_MAX;
            for (int j = i + 1; j < n; ++j){
                if (points[j][1] >= points[i][1] && y > points[j][1]){
                    result++;
                    y = points[j][1];
                }
            }
        }

        return result;
    }
};