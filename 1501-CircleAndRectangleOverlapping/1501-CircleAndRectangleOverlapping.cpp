// Last updated: 13/07/2026, 22:12:33
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = clamp(xCenter, x1, x2);
        int closestY = clamp(yCenter, y1, y2);
        
        int distX = xCenter - closestX;
        int distY = yCenter - closestY;
        int distSq = distX * distX + distY * distY;
        
        return distSq <= radius * radius;
    }
};