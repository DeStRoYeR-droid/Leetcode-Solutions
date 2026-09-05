// Last updated: 05/09/2026, 16:41:09
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