// Last updated: 06/07/2026, 19:08:00
class Solution {
private:
    int n;
    static int dirs[4][2];
    
    bool outOfBounds(const int& r, const int& c, const int& n){
        return (r < 0 || c < 0 || r >= n || c >= n);
    }

    int dfs(const int& r, const int& c, const int& label, vector<vector<int>>& grid){        
            if (outOfBounds(r, c, n) || grid[r][c] != 1) 
                return 0;

            grid[r][c] = label;
            int size = 1;
            for (const auto& dir : dirs){
                size += dfs(r + dir[0], c + dir[1], label, grid);
            }
            return size;
        }

        int connect(const int& r, const int& c, const unordered_map<int, int>& sizes, vector<vector<int>>& grid){
            unordered_set<int> visited;
            int result = 1;
            for (const auto& dir : dirs){
                if (!outOfBounds(r + dir[0], c + dir[1], n) &&
                    !visited.contains(grid[r + dir[0]][c + dir[1]])){
                        result += sizes.at(grid[r + dir[0]][c + dir[1]]);
                        visited.insert(grid[r + dir[0]][c + dir[1]]);
                }
            }
            return result;
        }

public:
    int largestIsland(vector<vector<int>>& grid) {
        this->n = grid.size();

        unordered_map<int, int> sizes;
        sizes[0] = 0;
        int result = 0;
        int label = 2;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    sizes[label] = dfs(i, j, label, grid);
                    result = max(result, sizes[label]);
                    ++label;
                }
            }
        }

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 0) 
                    result = max(result, connect(i, j, sizes, grid));
            }
        }
        return result;
    }
};
int Solution::dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};