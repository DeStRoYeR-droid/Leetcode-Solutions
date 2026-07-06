// Last updated: 06/07/2026, 18:50:10
static const int MOD = 1e9 + 7;
class Solution {
public:
    int factorial(int n){
        long long result = 1;
        for (int i = n; i > 1; --i){
            result = (result * i) % MOD;
        }
        return result;
    }

    int countPermutations(vector<int>& complexity) {
        const int n = complexity.size();
        for (int i = 1; i < n; ++i){
            if (complexity[0] >= complexity[i]) return 0;
        }
        return factorial(n - 1);
    }
};