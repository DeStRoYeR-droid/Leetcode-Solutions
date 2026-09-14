// Last updated: 14/09/2026, 09:19:54
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