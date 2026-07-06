// Last updated: 06/07/2026, 18:54:46
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long result = 0, equals = 0;

        unordered_map<int, long long> mpp;
        mpp[0] = 1LL;

        for (const int& i : nums){
            if (i % modulo == k) equals++;

            int rem = equals % modulo;
            int needed = (rem - k + modulo) % modulo;

            result += mpp[needed];
            mpp[rem]++;
        }

        return result;
    }
};