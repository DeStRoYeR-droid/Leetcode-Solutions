// Last updated: 06/07/2026, 19:07:08
class Solution {
public:
    static const int N = 50;
    static const int DRAW = 0, MOUSE = 1, CAT = 2;

    int color[N][N][3] = {};
    int degree[N][N][3] = {};

    vector<vector<int>> parents(const vector<vector<int>>& graph, int m, int c, int t) {
        vector<vector<int>> ans;
        if (t == CAT) {
            for (int m2 : graph[m]) {
                ans.push_back({m2, c, MOUSE});
            }
        } else {
            for (int c2 : graph[c]) {
                if (c2 != 0) {
                    ans.push_back({m, c2, CAT});
                }
            }
        }
        return ans;
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        for (int m = 0; m < n; ++m) {
            for (int c = 0; c < n; ++c) {
                degree[m][c][MOUSE] = graph[m].size();
                degree[m][c][CAT] = graph[c].size();
                for (int x : graph[c]) {
                    if (x == 0) {
                        degree[m][c][CAT]--;
                        break;
                    }
                }
            }
        }

        queue<vector<int>> q;
        for (int i = 0; i < n; ++i) {
            for (int t = 1; t <= 2; ++t) {
                color[0][i][t] = MOUSE;
                q.push({0, i, t, MOUSE});
                if (i > 0) {
                    color[i][i][t] = CAT;
                    q.push({i, i, t, CAT});
                }
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int i = node[0], j = node[1], t = node[2], c = node[3];
            for (auto& parent : parents(graph, i, j, t)) {
                int i2 = parent[0], j2 = parent[1], t2 = parent[2];
                if (color[i2][j2][t2] == DRAW) {
                    if (t2 == c) {
                        color[i2][j2][t2] = c;
                        q.push({i2, j2, t2, c});
                    } else {
                        degree[i2][j2][t2]--;
                        if (degree[i2][j2][t2] == 0) {
                            color[i2][j2][t2] = 3 - t2;
                            q.push({i2, j2, t2, 3 - t2});
                        }
                    }
                }
            }
        }

        return color[1][2][MOUSE];
    }
};