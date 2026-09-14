// Last updated: 14/09/2026, 09:21:29
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i != n / i) {
                    factors.push_back(n / i);
                }
            }
        }
        
        sort(factors.begin(), factors.end());
        return k <= factors.size() ? factors[k - 1] : -1;
    }
};
