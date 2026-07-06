// Last updated: 06/07/2026, 19:06:01
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (char instruction: instructions) {
            if (instruction == 'G') {
                x += dx[dir];
                y += dy[dir];
            } else if (instruction == 'L') {
                dir = (dir + 3) % 4;
            } else if (instruction == 'R') {
                dir = (dir + 1) % 4;
            }
        }

        return (x == 0 && y == 0) || (dir != 0);
    }
};