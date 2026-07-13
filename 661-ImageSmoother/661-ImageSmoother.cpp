// Last updated: 13/07/2026, 22:17:27
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int length = img.size();
        int width = img[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < length; i++){
            vector<int> row;
            for (int j = 0; j < width; j++){
                // Get the data for the cell
                int no_cell = 0;
                int result = 0;
                for (int k = -1; k < 2; k++){
                    if ((i + k) < 0 || (i+k) >= length) continue;
                    for (int l = -1; l < 2; l++){
                        if ((j + l) < 0 || (j+l) >= width) continue;
                        result += img[i + k][j + l];
                        no_cell++;
                    }
                }
                row.push_back(result/no_cell);
            }
            result.push_back(row);
        }
        return result;
    }
};