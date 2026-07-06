// Last updated: 06/07/2026, 18:54:15
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for (int i = 0; i <= min(n, limit); ++i) {
            for (int j = 0; j <= min(n - i, limit); ++j) {
                int k = n - i - j;
                if (k <= limit) {
                    count++;
                }
            }
        }
        return count;
    }
};