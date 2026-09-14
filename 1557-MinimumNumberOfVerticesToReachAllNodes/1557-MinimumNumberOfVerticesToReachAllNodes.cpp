// Last updated: 14/09/2026, 09:20:23
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