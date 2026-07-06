// Last updated: 06/07/2026, 18:53:01
static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        const int n = queries.size();
        vector<int> result(n, 0);
        unordered_map<int, int> colorCount;
        unordered_map<int, int> balls;

        int distinct = 0;
        int ball, color;
        for (int i = 0; i < n; ++i){        
            ball = queries[i][0];
            color = queries[i][1];

            if (balls.count(ball)){
                if (--colorCount[balls[ball]] == 0) {colorCount.erase(balls[ball]); --distinct;}
            }
            balls[ball] = color;
            if (++colorCount[color] == 1) ++distinct;

            result[i] = distinct;
        }
        
        return result;
    }
};