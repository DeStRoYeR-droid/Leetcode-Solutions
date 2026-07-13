// Last updated: 13/07/2026, 22:28:36
class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, r = 46340;
        while (l <= r){
            long long m = l + (r - l) / 2;
            if ((m * m) < x && ((m + 1) * (m + 1)) > x) return m;
            if ((m * m) > x) r = m - 1;
            else l = m + 1;
        }
        return l - 1;
    }
};