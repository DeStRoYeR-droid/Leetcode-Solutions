// Last updated: 13/07/2026, 22:17:44
class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);

        while (l <= r){
            long long curr = pow(l, 2) + pow(r, 2);
            if (curr == c) return true;
            else if (curr < c) ++l;
            else --r;
        }
        return false;
    }
};