// Last updated: 06/07/2026, 19:07:01
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int length = matrix.size();
        for (int i = 1; i < length; i++){
            for (int j = 0; j < length; j++){
                int min_num = INT_MAX;
                for (int k = max(0 , j-1); k < min(length, j+2); k++)
                    min_num = min(min_num, matrix[i-1][k]);
                matrix[i][j] += min_num;
            }
        }

        return *min_element(matrix[length-1].begin() , matrix[length-1].end());
    }
};