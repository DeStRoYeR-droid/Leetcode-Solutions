// Last updated: 06/07/2026, 18:56:06
static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        static const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int rows = grid.size();
        const int cols = grid[0].size();
        const int k = queries.size();
        
        vector<pair<int, int>> sortedQueries(k);
        for (int i = 0; i < k; ++i){
            sortedQueries[i] = make_pair(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(k, 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        minHeap.emplace(grid[0][0], make_pair(0, 0));
        visited[0][0] = true;

        int points = 0;

        for (auto& [value, index] : sortedQueries){
            while (!minHeap.empty() && minHeap.top().first < value){
                auto [val, pos] = minHeap.top(); minHeap.pop();
                int row = pos.first, col = pos.second;

                points++;
                for (auto& [dr, dc] : directions){
                    int nr = row + dr, nc = col + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]){
                        minHeap.emplace(grid[nr][nc], make_pair(nr, nc));
                        visited[nr][nc] = true;
                    }
                }
            }

            result[index] = points;
        }

        return result;
    }
};