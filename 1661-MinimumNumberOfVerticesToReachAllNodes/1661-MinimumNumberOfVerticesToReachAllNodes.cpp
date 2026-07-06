// Last updated: 06/07/2026, 19:02:21
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n, false);

        for (auto &e : edges) {
            hasIncoming[e[1]] = true;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!hasIncoming[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};