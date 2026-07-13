// Last updated: 13/07/2026, 22:18:52
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        if (mat.empty() && mat[0].empty()) return result;

        const int rows = mat.size(), cols = mat[0].size();
        result.reserve(rows * cols);

        int row = 0, col = 0;
        for (int i = 0; i < rows * cols; ++i){
            result.push_back(mat[row][col]);

            if ((row + col) % 2 == 0){
                if (col == cols - 1) ++row;
                else if (row == 0) ++ col;
                else {--row; ++ col;}
            }
            else {
                if (row == rows - 1) ++col;
                else if (col == 0) ++row;
                else {++row; --col;}
            }
        }
        return result;
    }

};