// Last updated: 06/07/2026, 19:05:38
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int n = arr.size();
        vector<int> candidates = {
            arr[0],
            arr[n / 4],
            arr[n / 2],
            arr[3 * n / 4]
        };

        for (int x : candidates) {
            int left = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int right = std::upper_bound(arr.begin(), arr.end(), x) - arr.begin();

            if (right - left > n / 4) {
                return x;
            } 
        }

        return arr.back();
    }
};