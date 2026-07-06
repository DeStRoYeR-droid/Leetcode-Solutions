// Last updated: 06/07/2026, 18:53:53
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        if (dimensions.size() == 0) return 0;

        int maxDiag = 0, maxArea = 0;
        for (const auto& dimension: dimensions){
            int diag = (dimension[0] * dimension[0]) + (dimension[1] * dimension[1]);
            int area = dimension[0] * dimension[1];

            if (diag > maxDiag){
                maxDiag = diag;
                maxArea = area;
            }
            else if (diag == maxDiag) maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};