// Last updated: 06/07/2026, 19:05:14
static const int MOD = 1e9 + 7;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int n = arr.size();
        long long total = accumulate(arr.begin(), arr.end(), 0LL), sum = 0, curSum = 0;

        for (int i = 0; i < n * min(k, 2); ++i){
            curSum = max<long long>(curSum + arr[i % n], arr[i % n]);
            sum = max(curSum, sum);
        }

        return max<long long>({0, sum, sum + total * max(0, k -2)}) % MOD;
    }
};