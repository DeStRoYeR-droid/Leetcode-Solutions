// Last updated: 06/07/2026, 18:46:49
class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, underscore = 0;
        int result = 0;
        int dist = 0;
        for (const char& ch: moves){
            x += (ch == 'R');
            x -= (ch == 'L');
            y += (ch == 'U');
            y -= (ch == 'D');
            underscore += (ch == '_');
        }
        result = abs(x) + abs(y) + underscore;
        return result;
    }
};