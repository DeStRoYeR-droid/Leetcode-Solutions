// Last updated: 08/08/2026, 11:14:11
class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i < n + 10; ++i){
            if (prodDigits(i) % t == 0) return i;
        }        
        return -1;
    }
    int prodDigits(int n){
        int result = 1;
        while (n){
            result *= n % 10; n /= 10;
        }
        return result;
    }
};