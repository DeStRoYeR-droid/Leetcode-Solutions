// Last updated: 24/08/2026, 22:35:32
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        long long min_coin = *min_element(coins.begin(), coins.end());
        long long hi = min_coin * k;
        long long lo = 1;

        int max_mask = 1 << n;
        vector<long long> memo_lcm(max_mask, 1);
        
        for (int mask = 1; mask < max_mask; ++mask){
            long long curr = 1;
            for (int i = 0; i < n; ++i){
                if ((mask >> i) & 1){
                    long long coin = coins[i];
                    long long A = curr / gcd(curr, coin);

                    if (A > hi / coin){
                        curr = hi + 1;
                        break;
                    }
                    else {
                        curr = A * coin;
                    }
                }
            }
            memo_lcm[mask] = curr;
        }

        auto count = [&](long long x){
            long long total = 0;
            for (int mask = 1; mask < max_mask; ++mask){
                if (memo_lcm[mask] > x) continue;
                if (__builtin_popcount(mask) % 2){
                    total += x / memo_lcm[mask];
                }
                else {
                    total -= x / memo_lcm[mask];
                }
            }
            return total;
        };

        long long result = hi;
        while (lo <= hi){
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k){
                result = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return result;
    }
};