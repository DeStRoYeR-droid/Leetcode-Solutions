// Last updated: 09/07/2026, 23:53:43
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countEffective(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // Step 1: Find the target bitwise OR of the entire array (S)
        int S = 0;
        for (int num : nums) {
            S |= num;
        }
        
        // Edge Case: If S is 0, all elements are 0. No subset can have OR strictly less than 0.
        if (S == 0) return 0;

        // Step 2: Map the set bits of S to contiguous indices [0, k-1]
        // This compresses our DP state space from O(2^30) down to O(2^k), where k is popcount(S)
        vector<int> bit_map(30, -1);
        int k = 0;
        for (int bit = 0; bit < 30; ++bit) {
            if ((S >> bit) & 1) {
                bit_map[bit] = k++;
            }
        }

        // Step 3: Build the initial frequency table for compressed masks
        // dp[mask] will initially store how many numbers directly equal that compressed mask
        int total_masks = 1 << k;
        vector<int> dp(total_masks, 0);
        
        for (int num : nums) {
            int compressed_mask = 0;
            for (int bit = 0; bit < 30; ++bit) {
                if ((num >> bit) & 1) {
                    compressed_mask |= (1 << bit_map[bit]);
                }
            }
            dp[compressed_mask]++;
        }

        // Step 4: Sum Over Subsets (SOS) DP
        // Propagate counts so dp[mask] stores the number of elements that are SUBMASKS of `mask`
        for (int i = 0; i < k; ++i) {
            for (int mask = 0; mask < total_masks; ++mask) {
                // If the i-th bit is set in mask, add the count from the state where i-th bit is 0
                if (mask & (1 << i)) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }

        // Step 5: Precompute powers of 2 modulo 10^9 + 7
        // pow2[c] represents the number of subsets we can form from `c` elements
        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        // Step 6: Apply Principle of Inclusion-Exclusion (PIE)
        // We count subsets whose bitwise OR is EXACTLY equal to S
        long long ways_equal_S = 0;
        
        for (int mask = 0; mask < total_masks; ++mask) {
            int set_bits = __builtin_popcount(mask);
            int bits_missing = k - set_bits;
            
            // Subsets formed exclusively by elements within `mask`
            long long subsets_count = pow2[dp[mask]];
            
            // If we miss an odd number of bits, subtract from total; if even, add to total
            if (bits_missing % 2 == 1) {
                ways_equal_S = (ways_equal_S - subsets_count + MOD) % MOD;
            } else {
                ways_equal_S = (ways_equal_S + subsets_count) % MOD;
            }
        }

        // Step 7: Calculate complement
        // Total subsets is 2^n. We subtract the subsets that equal S to get subsets strictly less than S.
        long long total_subsets = pow2[n];
        long long ans = (total_subsets - ways_equal_S + MOD) % MOD;

        return static_cast<int>(ans);
    }
};