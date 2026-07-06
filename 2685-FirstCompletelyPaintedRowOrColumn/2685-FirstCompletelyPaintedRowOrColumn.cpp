// Last updated: 06/07/2026, 18:55:41
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int rows = mat.size();
        const int cols = mat[0].size();

        vector<pair<int, int>> vals = vector<pair<int, int>>(rows * cols + 1);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) 
                vals[mat[i][j] - 1] = {i, j};
        
        vector<int> row_sum(rows, cols);
        vector<int> col_sum(cols, rows);

        int index = 0;
        for (const int& val : arr){
            auto [x, y] = vals[val - 1];
            if (row_sum[x] == 1 || col_sum[y] == 1) return index;
            row_sum[x]--;
            col_sum[y]--;
            index++;
        }
        
        return -1;
    }
};