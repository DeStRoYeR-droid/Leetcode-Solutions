// Last updated: 06/07/2026, 18:59:14
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int n = grid.size();
        vector<int> values;

        for (const auto& row : grid){
            for (const int& val : row) values.push_back(val);
        }

        sort(values.begin(), values.end());

        for (const int& val : values){
            if (abs(val - values[0]) % x != 0) return -1;
        }

        int result = 0;
        int median = values[values.size() / 2];
        for (const int& val : values){
            result += (abs(val - median)) / x;
        }
        return result;
    }
};