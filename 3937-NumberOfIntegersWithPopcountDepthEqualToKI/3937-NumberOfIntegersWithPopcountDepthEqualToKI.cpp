// Last updated: 06/07/2026, 18:49:48
class Solution {
public:
    long long C[65][65];
    void precompute(){  // Pascal's triangle logic
        for (int i = 0; i <= 62; ++i){
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j){
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    int getDepth(long long x){
        int depth = 0;
        while (x > 1){
            x = __builtin_popcountll(x);
            ++depth;
        }
        return depth;
    }

    long long countWithExactBits(long long n, int target_bits){
        if (target_bits == 0) return 0; // we only want positive integers

        long long count = 0;
        for (int j = 62; j >= 0; --j){
            if ((n >> j) & 1){
                if (target_bits >= 0 && j >= target_bits){
                    count += C[j][target_bits];
                }
                --target_bits;
            }
            if (target_bits < 0) break;
        }

        if (target_bits == 0) ++count;
        return count;
    }
    long long popcountDepth(long long n, int k) {
        if (k == 0) return (n >= 1) ? 1 : 0;

        precompute();
        long long result = 0;
        for (int i = 1; i <= 62; ++i){
            if (getDepth(i) == k - 1) result += countWithExactBits(n, i);
        }

        if (k == 1 & n >= 1) --result;
        return result;
    }
};