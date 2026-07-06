// Last updated: 06/07/2026, 19:02:09
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        const int n = arr.size();
        int result = 0;
        for (int i = 0; i < n; ++i){
            for (int len = 1; len < n - i + 1; len += 2){
                result += accumulate(arr.begin() + i, arr.begin() + i + len, 0);
            }
        }
        return result;
    }
};