// Last updated: 06/07/2026, 18:47:40
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