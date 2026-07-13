// Last updated: 13/07/2026, 22:16:56
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            int n = i, ok = 1;
            while (n) {
                int d = n % 10;
                if (d == 0 || i % d != 0) {
                    ok = 0;
                    break;
                }
                n /= 10;
            }
            if (ok) res.push_back(i);
        }
        return res;
    }
};