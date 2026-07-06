// Last updated: 06/07/2026, 19:02:13
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int length = arr.size();
        int left = 0;
        int right = length - 1;

        while (left+1 < length && arr[left] <= arr[left+1]) ++left;
        if (left == right) return 0;

        while (right > 0 && arr[right - 1] <= arr[right]) --right;
        
        int result = min(length - left - 1, right);
        for (int l = 0, r = right; l <= left; l++){
            while (r < length && arr[r] < arr[l]) ++r;
            result = min(result, r - l - 1);
        }
        return result;
    }
};