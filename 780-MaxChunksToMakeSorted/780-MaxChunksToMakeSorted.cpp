// Last updated: 13/07/2026, 22:16:21
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        int count = 0;
        int difference = 0;
        for (int i = 0; i < n; i++){
            difference += arr[i] - i;
            count += (difference == 0);
        }
        return count;
    }
};