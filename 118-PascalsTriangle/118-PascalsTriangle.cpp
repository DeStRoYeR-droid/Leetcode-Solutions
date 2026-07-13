// Last updated: 13/07/2026, 22:26:45
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        for (int i = 1; i < numRows; i++){
            vector<int> row = vector<int>(i+1 , 1);
            for (int j = 1; j < i; j++){
                row[j] = result[i-1][j] + result[i-1][j-1];
            }
            result.push_back(row);
        }
        return result;
    }
};