// Last updated: 06/07/2026, 18:59:45
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int c = 0;
        int mini = INT_MAX;
        const int n = matrix.size();
        const int m = matrix[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) {
                    c++;
                }
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(c % 2) sum -= 2*mini;

        return sum;
    }
};