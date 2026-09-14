// Last updated: 14/09/2026, 09:36:18
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