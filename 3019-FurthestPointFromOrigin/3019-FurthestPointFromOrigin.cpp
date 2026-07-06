// Last updated: 06/07/2026, 18:54:37
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int d = 0, m = 0;
        for (const char& ch : moves){
            d += (ch == 'L');
            d -= (ch == 'R');
            m += (ch == '_');
        }
        return abs(d) + m;
    }
};