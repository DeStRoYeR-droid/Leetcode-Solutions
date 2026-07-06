// Last updated: 06/07/2026, 18:46:55
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int result = 0;
        for (int i = 0; i <= 200; ++i){
            if ((abs(n - i) <= k) && ((n & i) == 0)) result += i;
        }
        return result;
    }
};