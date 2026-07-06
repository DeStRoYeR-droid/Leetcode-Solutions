// Last updated: 06/07/2026, 18:52:50
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // atexit(+[](){ofstream("display_runtime.txt") << 0 << '\n';});
        const int rows = grid.size(), cols = grid[0].size();
        ios_base::sync_with_stdio(false);
        int minrow=INT_MAX,maxrow=INT_MIN,mincol=INT_MAX,maxcol=INT_MIN;
        
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j]){
                    minrow=min(i,minrow);
                    maxrow=max(i,maxrow);
                    mincol=min(j,mincol);
                    maxcol=max(j,maxcol);
                }
            }
        }
        return (maxrow-minrow+1)*(maxcol-mincol+1);
    }
};