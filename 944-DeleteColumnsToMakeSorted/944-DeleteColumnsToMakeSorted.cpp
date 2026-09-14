// Last updated: 14/09/2026, 09:31:30
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols = strs[0].size(), rows = strs.size();

        int result = 0;
        for(int col = 0; col < cols; col++) {
            for(int row = 0; row < rows - 1; row++) {
                if(strs[row][col] > strs[row + 1][col]) {
                    ++result;
                    break;
                }
            }
        }

        return result;   
    }
};