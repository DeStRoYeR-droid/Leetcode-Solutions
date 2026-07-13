// Last updated: 13/07/2026, 22:20:29
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];

        while (lo < hi){
            int mid = lo + (hi - lo) / 2;

            int count = 0;
            int col = n - 1;

            for (int i = 0; i < n; ++i){
                while (col >= 0 && matrix[i][col] > mid) col -= 1;
                count += col + 1;
            }

            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};