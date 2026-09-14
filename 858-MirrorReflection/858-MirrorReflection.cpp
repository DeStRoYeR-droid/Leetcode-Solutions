// Last updated: 14/09/2026, 09:33:46
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int gcd_pq = gcd(p, q);
        int m = q / gcd_pq;
        int n = p / gcd_pq;
    
        m = (p / gcd_pq);
        n = (q / gcd_pq);
    
        if (m % 2 == 0 && n % 2 == 1) return 2;
        if (m % 2 == 1 && n % 2 == 1) return 1;
        if (m % 2 == 1 && n % 2 == 0) return 0;
    
        return -1;
    }
};