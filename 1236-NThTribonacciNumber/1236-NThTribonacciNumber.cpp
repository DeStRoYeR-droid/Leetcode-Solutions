// Last updated: 06/07/2026, 19:05:30
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int result = 0;
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        int iter = 0;
        while (iter < n - 2){
            result = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = result;
            iter++;
        }
        return result;
    }
};