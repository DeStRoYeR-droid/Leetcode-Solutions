// Last updated: 13/07/2026, 22:30:39
class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        long long y = x;
        y = abs(y);
        long long reverse = 0;
        while (y){
            reverse = reverse * 10 + y % 10;
            if (reverse > INT_MAX) return 0;
            y /= 10;
        }
        return reverse * sign;
    }
};