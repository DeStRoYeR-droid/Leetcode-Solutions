// Last updated: 06/07/2026, 19:06:54
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        const int n = arr.size();
        if (n < 3) return false;
        
        vector<bool> left(n, false), right(n, false);
        left[0] = true;
        right[n - 1] = true;

        for (int i = 1; i < n - 1; ++i){
            if (arr[i] > arr[i - 1]) left[i] = true;
            else break;
        }

        for (int i = n - 2; i >= 0; --i){
            if (arr[i] > arr[i + 1]) right[i] = true;
            else break;
        }

        for (int i = 1; i < n - 1; ++i){
            if (left[i] && right[i]) return true;
        }
        return false;
    }
        
};