// Last updated: 14/09/2026, 09:16:32
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