// Last updated: 06/07/2026, 18:51:59
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mini = 1e9 + 1, maxi = -1e9 - 1, result = 0;
        for (const int& val: nums){
            mini = min(mini, val);
            maxi = max(maxi, val);
        }

        vector<int> freq(maxi + 1, 0);
        for (const int& val : nums) freq[val]++;
        for (int i = 1; i <= maxi; ++i) freq[i] += freq[i - 1];

        for (int cur = mini; cur <= maxi; ++cur){
            int l = max(mini, cur - k);
            int r = min(maxi, cur + k);

            int f = freq[cur] - freq[cur - 1];

            int opReq = min(numOperations, freq[r] - freq[l - 1] - f);
            result = max(result, f + opReq);
        }

        return result;
    }
};