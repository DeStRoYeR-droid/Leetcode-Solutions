// Last updated: 02/08/2026, 14:36:01
class Solution {
    bool binarySearch(const vector<int>& array, int target, int right, int left = 0){
        while (left <= right){
            int mid = (left + right) / 2;
            if (array[mid] > target) right = mid - 1;
            else if (array[mid] < target) left = mid + 1;
            else return true;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cur_row = 0;
        const int cols = matrix[0].size() - 1;
        bool result = false;

        while (cur_row < matrix.size()){
            if (matrix[cur_row][0] > target) break;
            else {
                if (binarySearch(matrix[cur_row], target, cols, 0)) return true;
            }
            cur_row++;
        }
        return result;
    }
};