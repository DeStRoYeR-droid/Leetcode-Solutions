// Last updated: 07/09/2026, 22:40:48
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