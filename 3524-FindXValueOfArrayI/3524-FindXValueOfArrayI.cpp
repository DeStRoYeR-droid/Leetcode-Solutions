// Last updated: 30/09/2026, 18:16:14
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k);
        int freq[5] = {0};

        for (int n : nums){
            n %= k;
            int cur[5] = {0};
            cur[n] = 1;

            for (int x = 0; x < k; ++x) cur[x * n % k] += freq[x];
            for (int x = 0; x < k; ++x){
                freq[x] = cur[x];
                result[x] += freq[x];
            }
        }
        return result;
    }
};