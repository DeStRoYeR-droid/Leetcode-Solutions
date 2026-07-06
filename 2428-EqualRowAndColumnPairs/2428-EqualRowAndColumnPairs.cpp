// Last updated: 06/07/2026, 18:57:10
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int size = grid.size();
        int result = 0;
        map<vector<int>, int> seen;

        for (const auto& row : grid) seen[row]++;

        for (int i = 0; i < size; i++){
            vector<int> v(size);
            for (int j = 0; j < size; j++) v[j] = grid[j][i];
            result += seen[v];
        }
        return result;
    }
};