// Last updated: 06/07/2026, 19:00:02
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int, int>>q;
        q.push({e[0], e[1]});

        int moves = 1;
        const int rows = maze.size();
        const int cols = maze[0].size();

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        maze[e[0]][e[1]] = '+';
        while (!q.empty()){
            int l = q.size();
            for (int k = 0; k < l; ++k){
                auto [i,j] = q.front(); q.pop();

                for (int m = 0; m < 4; ++m){
                    int x = i + dirs[m][0];
                    int y = j + dirs[m][1];

                    if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == '+') continue;
                    if (x == 0 || y == 0 || x == rows - 1 || y == cols - 1) return moves;

                    maze[x][y] = '+';
                    q.push({x,y});
                }
            }
            moves++;
        }
        return -1;
    }
};