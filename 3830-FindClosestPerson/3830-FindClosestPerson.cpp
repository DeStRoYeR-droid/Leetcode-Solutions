// Last updated: 06/07/2026, 18:50:28
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distX = abs(x - z);
        int distY = abs(y - z);

        if (distX == distY) return 0;
        else if (distX > distY) return 2;
        else return 1;
    }
};