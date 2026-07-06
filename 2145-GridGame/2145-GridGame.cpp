// Last updated: 06/07/2026, 18:59:20
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long result = LLONG_MAX;
        long long row1_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long row2_sum = 0;
        
        for (int i = 0; i < grid[0].size(); i++){
            row1_sum -= grid[0][i];
            result = min(result, max(row1_sum, row2_sum));
            row2_sum += grid[1][i];
        }
        return result;
    }
};