// Last updated: 14/09/2026, 09:20:49
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        static const int mod = 1e9 + 7;
        long long oddCount = 0, prefix = 0;
        for (const int& num : arr){
            prefix += num;
            oddCount += prefix % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % mod;
    }
};