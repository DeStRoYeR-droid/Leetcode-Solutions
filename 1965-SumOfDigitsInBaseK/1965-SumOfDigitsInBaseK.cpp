// Last updated: 06/07/2026, 19:00:38
class Solution {
public:
    int sumBase(int n, int k) {
        int result = 0;
        while (n){
            result += n % k;
            n = n / k;
        }
        return result;
    }
};