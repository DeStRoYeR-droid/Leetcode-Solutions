// Last updated: 05/09/2026, 16:40:53
class Solution {
public:
    bool checkGoodInteger(int n) {
        int ss = 0, ds = 0;
        while (n > 0){
            int d = n % 10; n /= 10;
            ss += (d * d);
            ds += d;
        }
        return (ss - ds) >= 50;
    }
};