// Last updated: 13/07/2026, 22:17:28
class Solution {
public:
    bool judgeCircle(string moves) {
        int dirX = 0, dirY = 0;
        for (const char& ch : moves){
            if (ch == 'R') ++dirX;
            else if (ch == 'L') --dirX;
            else if (ch == 'U') ++dirY;
            else --dirY;
        }
        return (dirX == 0) && (dirY == 0);
    }
};