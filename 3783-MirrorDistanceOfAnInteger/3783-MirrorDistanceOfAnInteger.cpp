// Last updated: 07/09/2026, 22:23:45
class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
    int reverse(int n){
        int result = 0;
        while (n){
            result = result * 10 + n % 10;
            n = n / 10;
        }
        return result;
    }
};