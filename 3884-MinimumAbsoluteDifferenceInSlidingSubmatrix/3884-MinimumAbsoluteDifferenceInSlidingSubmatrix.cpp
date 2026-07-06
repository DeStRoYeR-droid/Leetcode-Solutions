// Last updated: 06/07/2026, 18:50:07
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));
        if (k == 1) return result;

        for (int i = 0; i < m - k + 1; ++i){
            for (int j = 0; j < n - k + 1; ++j){
                vector<int> arr;
                for (int l = 0; l < k; ++l){
                    for (int p = 0; p < k; ++p){
                        arr.push_back(grid[i + l][j + p]);
                    }
                }
                sort(arr.begin(),arr.end());
                int left = 0, mini = 1e9, right;
                for(right = 1; right < k * k; ++right){
                    if (arr[right] == arr[left]) continue;
                    else{
                        mini = min(mini, arr[right] - arr[left]);
                        left = right;
                    }
                }
                if (left == 0 && right == k * k) result[i][j] = 0;
                else result[i][j] = mini;
            }
        }

        return result;
    }
};