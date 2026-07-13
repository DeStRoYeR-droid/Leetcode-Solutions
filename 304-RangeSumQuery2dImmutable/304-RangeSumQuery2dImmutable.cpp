// Last updated: 13/07/2026, 22:21:28
class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        mat.resize(n+1,vector<int>(m+1,0));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                mat[i][j] = matrix[i - 1][j - 1] + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return mat[row2][col2]-mat[row1-1][col2]-mat[row2][col1-1]+
        mat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */