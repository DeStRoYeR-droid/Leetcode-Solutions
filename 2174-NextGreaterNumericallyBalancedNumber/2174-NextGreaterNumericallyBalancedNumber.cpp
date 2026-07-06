// Last updated: 06/07/2026, 18:59:09
class Solution {
public:
    bool isBalance(int x) {
        int cnt[9] = {0};
        while(x > 0) {
            if (x % 10 == 0) return false;
            cnt[x % 10 - 1]++;
            x /= 10;
        }

        for (int i = 0; i < 9; i++) {
            if (cnt[i] > 0 && cnt[i] != i + 1) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        if (n == 0) return 1;
        for (int i = n + 1; i <= n * 100; ++i)
            if (isBalance(i)) return i;
        return -1;
    }
};