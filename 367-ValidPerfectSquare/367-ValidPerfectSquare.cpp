// Last updated: 13/07/2026, 22:20:41
class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num / 2 + 1;
        while (l <= r){
            long m = l + (r - l) / 2;
            if (m * m == num) return true;
            else if (m * m > (long) num) r = m - 1;
            else l = m + 1;
        }
        return false;
    }
};