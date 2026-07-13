// Last updated: 13/07/2026, 22:19:41
class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 1;
        --k;

        while (k > 0){
            int count = countSteps(n, result, result + 1);
            if (count <= k){
                ++result;
                k -= count;
            }
            else {
                result *= 10;
                --k;
            }
        }
        return result;
    }

    int countSteps(long long n, long long current, long long next){
        int steps = 0;
        while (current <= n){
            steps += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return steps;
    }
};