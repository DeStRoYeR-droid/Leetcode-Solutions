// Last updated: 06/07/2026, 19:07:11
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();
        vector<int> grid(n * n + 1, -1);
        int index = 1;
        bool right = true;

        for (int i = n - 1; i >= 0; --i){
            if (right) for (int j = 0; j < n; ++j) grid[index++] = board[i][j];
            else for (int j = n - 1; j >= 0; --j) grid[index++] = board[i][j];
            right = !right;
        }

        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1); visited[1] = true;
        int moves = 0;
        
        while (!q.empty()){
            int size = q.size();
            while (size--){
                int cur = q.front(); q.pop();
                if (cur == n * n) return moves;

                for (int num = 1; num <= 6 && cur + num <= n * n; ++num){
                    int next = cur + num;
                    if (grid[next] != -1) next = grid[next];
                    if (!visited[next]){
                        q.push(next); visited[next] = 1;
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};