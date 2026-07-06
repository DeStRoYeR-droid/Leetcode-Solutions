// Last updated: 06/07/2026, 19:08:12
class Solution {
public:
    double soupServings(int n) {
        if (n > 5000) return 1.0;
        int units = (n + 24) / 25;
        vector<vector<double>> cache(units + 1, vector<double>(units + 1, -1.0));
        return calcProb(units, units, cache);
    }

    double calcProb(int A, int B, vector<vector<double>>& cache){
        if (A <= 0 && B <= 0) return .5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (cache[A][B] != -1.0) return cache[A][B];
        double prob = .25 * (
            calcProb(A - 4, B, cache) +
            calcProb(A - 3, B - 1, cache) +
            calcProb(A - 2, B - 2, cache) +
            calcProb(A - 1, B - 3, cache)
        );
        cache[A][B] = prob;
        return prob;
    }
};