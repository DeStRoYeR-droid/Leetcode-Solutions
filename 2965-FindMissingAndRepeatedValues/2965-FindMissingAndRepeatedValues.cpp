// Last updated: 07/09/2026, 22:39:31
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> seen(n * n, 0);
        int a, b;
        for (const auto& row : grid){
            for (const int& value : row){
                seen[value-1]++;
            }
        }

        for (int i = 0; i < n * n; i++){
            if (seen[i] == 2) a = i + 1;
            else if (seen[i] == 0) b = i + 1;
        }


        return {a, b};
    }
};