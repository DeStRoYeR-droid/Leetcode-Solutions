// Last updated: 06/07/2026, 18:52:30

class Solution {
private:
    bool helper(int i) {
        if (i <= 1) return false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) return false;
        }
        return true;
    }

public:
    int nonSpecialCount(int l, int r) {
        int ind1 = ceil(sqrt(l));
        int ind2 = floor(sqrt(r));
        
        int cnt = 0;
        for (int i = ind1; i <= ind2; i++) {
            if (helper(i)) cnt++;
        }

        return (r - l + 1) - cnt;
    }
};