// Last updated: 06/07/2026, 18:49:33
#include <vector>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;

    // Helper function to multiply two matrices
    Matrix multiply(const Matrix& A, const Matrix& B, int size) {
        Matrix C(size, vector<long long>(size, 0));
        for(int i = 0; i < size; i++) {
            for(int k = 0; k < size; k++) {
                if (A[i][k] == 0) continue; // Optimization: skip 0s
                for(int j = 0; j < size; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Helper function for Binary Exponentiation of a matrix
    Matrix power(Matrix A, int p, int size) {
        Matrix res(size, vector<long long>(size, 0));
        // Initialize as Identity Matrix
        for(int i = 0; i < size; i++) res[i][i] = 1; 
        
        while(p > 0) {
            if(p % 2 == 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p /= 2;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        // Base case: If array length is 1, any of the 'm' numbers are valid.
        if (n == 1) return m;

        // Number of states: m values * 2 directions (UP = 0, DOWN = 1)
        int S = 2 * m; 
        Matrix M(S, vector<long long>(S, 0));

        // 1. Build the Adjacency Transition Matrix
        for (int u = 1; u <= m; u++) {
            int from_up = (u - 1) * 2 + 0;
            int from_down = (u - 1) * 2 + 1;

            // If we arrived at 'u' going UP, we MUST go DOWN to a smaller 'v'
            for (int v = 1; v < u; v++) {
                int to_down = (v - 1) * 2 + 1;
                M[to_down][from_up] = 1;
            }

            // If we arrived at 'u' going DOWN, we MUST go UP to a larger 'v'
            for (int v = u + 1; v <= m; v++) {
                int to_up = (v - 1) * 2 + 0;
                M[to_up][from_down] = 1;
            }
        }

        // 2. Raise Matrix to the power of (n - 2)
        Matrix T = power(M, n - 2, S);

        // 3. Create the Initial State Vector (V) for n = 2
        vector<long long> V(S, 0);
        for (int v = 1; v <= m; v++) {
            V[(v - 1) * 2 + 0] = v - 1;   // Ways to arrive at 'v' going UP
            V[(v - 1) * 2 + 1] = m - v;   // Ways to arrive at 'v' going DOWN
        }

        // 4. Multiply T * V to get final states, and sum the results
        long long total_ways = 0;
        for (int i = 0; i < S; i++) {
            long long current_ways = 0;
            for (int j = 0; j < S; j++) {
                current_ways = (current_ways + T[i][j] * V[j]) % MOD;
            }
            total_ways = (total_ways + current_ways) % MOD;
        }

        return total_ways;
    }
};