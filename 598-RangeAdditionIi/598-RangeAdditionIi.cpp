// Last updated: 13/07/2026, 22:18:00
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m, col = n;
        for (const auto& val : ops){
            row = min(row, val[0]);
            col = min(col, val[1]);
        }
        return row * col;
    }
};