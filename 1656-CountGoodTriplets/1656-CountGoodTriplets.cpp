// Last updated: 06/07/2026, 19:02:23
class Solution {
public:
    int countGoodTriplets(const vector<int>& arr, const int& a, const int& b, const int& c) {
        const int n = arr.size();
        int result = 0;
        for (int i = 0; i < n - 2; ++i){
            for (int j = i + 1; j < n - 1; ++j){
                if (abs(arr[i] - arr[j]) > a) continue;
                for (int k = j + 1; k < n; ++k){
                    if (abs(arr[i] - arr[k]) <= c && abs(arr[j] - arr[k]) <= b) ++result;
                }
            }
        }
        return result;
    }
};