// Last updated: 06/07/2026, 19:07:44
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