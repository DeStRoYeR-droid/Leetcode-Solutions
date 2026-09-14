// Last updated: 14/09/2026, 09:34:27
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int triangle = 0;
        int result = 0;
        for (int i = 1; triangle < n; ++i){
            if ((n - triangle) % i == 0) ++result;
            triangle += i;
        }
        return result;
    }
};