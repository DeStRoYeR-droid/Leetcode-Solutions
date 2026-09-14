// Last updated: 14/09/2026, 09:33:48
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};