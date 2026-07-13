// Last updated: 13/07/2026, 22:21:56
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        vector<int> indices = {0, 0, 0};
        vector<int> ugly(1, 1);

        for (int i = 1; i < n; i++){
            vector<int> nextUgly = {
                ugly[indices[0]] * primes[0],
                ugly[indices[1]] * primes[1],
                ugly[indices[2]] * primes[2]
            };

            int minVal = *min_element(nextUgly.begin(), nextUgly.end());
            ugly.push_back(minVal);

            for (int j = 0; j < 3; ++j) if (nextUgly[j] == minVal) ++indices[j];
        }
        return ugly[n-1];
    }
};