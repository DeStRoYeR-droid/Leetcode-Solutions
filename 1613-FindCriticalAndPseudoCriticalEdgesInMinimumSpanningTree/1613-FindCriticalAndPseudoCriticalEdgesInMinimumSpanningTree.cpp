// Last updated: 06/07/2026, 19:02:43
class UnionFind {
private:
    vector<int> parent, rank;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        return true;
    }
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int components() {
        unordered_set<int> roots;
        for (int i = 0; i < parent.size(); i++) roots.insert(find(i));
        return roots.size();
    }
    bool connect(int x, int y) { return unite(x, y); }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> newEdges(m);
        for (int i = 0; i < m; i++) {
            newEdges[i] = {edges[i][0], edges[i][1], edges[i][2], i};
        }
        sort(newEdges.begin(), newEdges.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        
        auto buildMST = [&](int forcedEdge, int ignoredEdge) -> int {
            UnionFind uf(n);
            int weight = 0;
            if (forcedEdge != -1) {
                uf.connect(newEdges[forcedEdge][0], newEdges[forcedEdge][1]);
                weight += newEdges[forcedEdge][2];
            }
            for (int i = 0; i < m; i++) {
                if (i == ignoredEdge) continue;
                if (uf.connect(newEdges[i][0], newEdges[i][1])) {
                    weight += newEdges[i][2];
                }
            }
            return uf.components() == 1 ? weight : INT_MAX;
        };
        
        int baseWeight = buildMST(-1, -1);
        vector<int> critical, pseudoCritical;
        
        for (int i = 0; i < m; i++) {
            if (buildMST(-1, i) > baseWeight)
                critical.push_back(newEdges[i][3]);
            else if (buildMST(i, -1) == baseWeight)
                pseudoCritical.push_back(newEdges[i][3]);
        }
        
        return {critical, pseudoCritical};
    }
};
