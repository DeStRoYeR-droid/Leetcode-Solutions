// Last updated: 14/09/2026, 09:18:15
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        for (int i = 1; i <= n / 7; ++i){
            result += 7 * (2 * i + 6) / 2;
        }
        // cout << "Remaining = " << n % 7 << " start = " << (n / 7 + 1) << endl;
        result += (n % 7) * (2 * (n / 7 + 1) + (n % 7 - 1)) / 2;
        return result;
    }
};