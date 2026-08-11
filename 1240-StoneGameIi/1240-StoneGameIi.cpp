// Last updated: 11/08/2026, 12:52:40
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // Building suffix array
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // Setup the Memoization Table
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        
        return dfs(0, 1, piles, suffixSum, memo);
    }
    
private:
    int dfs(int i, int m, const vector<int>& piles, const vector<int>& suffixSum, vector<vector<int>>& memo) {
        int n = piles.size();
        
        // Base Case: If we can sweep the rest of the board, take everything.
        if (i + 2 * m >= n) {
            return suffixSum[i];
        }
        
        // If already calculated, return the cached result.
        if (memo[i][m] != -1) {
            return memo[i][m];
        }
        
        int maxStones = 0;
        
        // Recursive Case: Try taking X piles (from 1 up to 2 * M)
        for (int x = 1; x <= 2 * m; ++x) {
            int currentScore = suffixSum[i] - dfs(i + x, max(m, x), piles, suffixSum, memo);
            maxStones = max(maxStones, currentScore);
        }
        
        // Save the result to our memo
        return memo[i][m] = maxStones;
    }
};