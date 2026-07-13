// Last updated: 13/07/2026, 22:26:43
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result = {1};
        for (int i = 1; i < rowIndex+1; i++){
            vector<int> row = vector<int>(i+1 , 1);
            for (int j = 1; j < i; j++){
                row[j] = result[j] + result[j-1];
            }
            result = row;
        }
        return result;
    }
};