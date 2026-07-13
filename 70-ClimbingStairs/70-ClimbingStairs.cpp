// Last updated: 13/07/2026, 22:28:35
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int result = 0;
        int prev1 = 2, prev2 = 3;
        for (int i = 3; i < n; i++){
            result = prev1 + prev2;
            prev1 = prev2;
            prev2 = result;
        }
        return result;
    }
};