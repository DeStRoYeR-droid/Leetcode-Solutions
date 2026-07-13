// Last updated: 13/07/2026, 22:28:28
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (const int& val : rows){
            for (int i = 0; i < matrix[0].size(); ++i){
                matrix[val][i] = 0;
            }
        }

        for (const int& val : cols){
            for (int i = 0; i < matrix.size(); ++i){
                matrix[i][val] = 0;
            }
        }
    }
};